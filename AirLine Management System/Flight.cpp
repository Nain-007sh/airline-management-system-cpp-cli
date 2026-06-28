#include "Flight.h"
#include "Dashboard.h"
#include "Passengers.h"
#include "Booking.h"
#include "ContactUs.h"
#include "ODBCHelper.h"

using namespace AirLineManagementSystem;
using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;

// =====================================================
// Helper: get city_id by name, if not exists insert it
// =====================================================
int GetOrCreateCityId_Airline(OdbcConnection^ con, OdbcTransaction^ tx, String^ cityName)
{
    String^ qFind = "SELECT city_id FROM cities WHERE city_name = ?";
    OdbcCommand^ cmdFind = gcnew OdbcCommand(qFind, con, tx);
    cmdFind->Parameters->AddWithValue("@p1", cityName);

    Object^ res = cmdFind->ExecuteScalar();
    if (res != nullptr && res != DBNull::Value)
        return Convert::ToInt32(res);

    String^ qIns = "INSERT INTO cities (city_name) VALUES (?)";
    OdbcCommand^ cmdIns = gcnew OdbcCommand(qIns, con, tx);
    cmdIns->Parameters->AddWithValue("@p1", cityName);
    cmdIns->ExecuteNonQuery();

    // reselect
    OdbcCommand^ cmdFind2 = gcnew OdbcCommand(qFind, con, tx);
    cmdFind2->Parameters->AddWithValue("@p1", cityName);

    Object^ res2 = cmdFind2->ExecuteScalar();
    if (res2 == nullptr || res2 == DBNull::Value)
        throw gcnew Exception("Failed to create city: " + cityName);

    return Convert::ToInt32(res2);
}

// =====================================================
// Helper: get route_id by from/to city, if not exists insert it
// =====================================================
int GetOrCreateRouteId_Airline(OdbcConnection^ con, OdbcTransaction^ tx, int fromCityId, int toCityId)
{
    String^ qFind = "SELECT route_id FROM routes WHERE from_city_id = ? AND to_city_id = ?";
    OdbcCommand^ cmdFind = gcnew OdbcCommand(qFind, con, tx);
    cmdFind->Parameters->AddWithValue("@p1", fromCityId);
    cmdFind->Parameters->AddWithValue("@p2", toCityId);

    Object^ res = cmdFind->ExecuteScalar();
    if (res != nullptr && res != DBNull::Value)
        return Convert::ToInt32(res);

    String^ qIns = "INSERT INTO routes (from_city_id, to_city_id) VALUES (?, ?)";
    OdbcCommand^ cmdIns = gcnew OdbcCommand(qIns, con, tx);
    cmdIns->Parameters->AddWithValue("@p1", fromCityId);
    cmdIns->Parameters->AddWithValue("@p2", toCityId);
    cmdIns->ExecuteNonQuery();

    // reselect
    OdbcCommand^ cmdFind2 = gcnew OdbcCommand(qFind, con, tx);
    cmdFind2->Parameters->AddWithValue("@p1", fromCityId);
    cmdFind2->Parameters->AddWithValue("@p2", toCityId);

    Object^ res2 = cmdFind2->ExecuteScalar();
    if (res2 == nullptr || res2 == DBNull::Value)
        throw gcnew Exception("Failed to create route.");

    return Convert::ToInt32(res2);
}

// =====================
// Load Flights (Grid)
// =====================
void Flight::LoadFlights()
{
    OdbcConnection^ con = ODBCHelper::GetConnection();

    String^ query =
        "SELECT "
        "  fl.flight_id, "
        "  fl.flight_code, "
        "  fl.base_price, "
        "  cf.city_name AS from_city, "
        "  ct.city_name AS to_city "
        "FROM flights fl "
        "JOIN routes r ON r.route_id = fl.route_id "
        "JOIN cities cf ON cf.city_id = r.from_city_id "
        "JOIN cities ct ON ct.city_id = r.to_city_id "
        "ORDER BY fl.flight_id DESC";

    try
    {
        OdbcDataAdapter^ da = gcnew OdbcDataAdapter(query, con);
        DataTable^ dt = gcnew DataTable();
        da->Fill(dt);

        dataGridView1->DataSource = dt;

        if (dataGridView1->Columns->Count > 0)
        {
            dataGridView1->Columns["flight_id"]->HeaderText = "Flight ID";
            dataGridView1->Columns["flight_code"]->HeaderText = "Flight Code";
            dataGridView1->Columns["base_price"]->HeaderText = "Base Price";
            dataGridView1->Columns["from_city"]->HeaderText = "From City";
            dataGridView1->Columns["to_city"]->HeaderText = "To City";
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error loading flights:\n" + ex->Message);
    }
    finally
    {
        if (con != nullptr && con->State == ConnectionState::Open)
            con->Close();
    }
}

// =====================
// Form Load
// =====================
System::Void Flight::Flight_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView1->ReadOnly = true;
    dataGridView1->AllowUserToAddRows = false;
    dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
    dataGridView1->MultiSelect = false;
    dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

    LoadFlights();
}

// =====================
// ADD FLIGHT (using your textboxes)
// textBox1 = flight_code
// textBox2 = from_city
// textBox3 = base_price
// textBox4 = to_city
// textBox5 = (optional unused)
// textBox6 = (optional unused)
// =====================
System::Void Flight::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ flightCode = textBox1->Text->Trim();
    String^ fromCity = textBox2->Text->Trim();
    String^ priceTxt = textBox3->Text->Trim();
    String^ toCity = textBox4->Text->Trim();

    if (flightCode == "" || fromCity == "" || priceTxt == "" || toCity == "")
    {
        MessageBox::Show("Please fill all fields (Flight Code, From City, Base Price, To City).");
        return;
    }

    if (fromCity->Equals(toCity, StringComparison::OrdinalIgnoreCase))
    {
        MessageBox::Show("From City and To City cannot be the same.");
        return;
    }

    double basePrice = 0;
    try
    {
        basePrice = Convert::ToDouble(priceTxt);
        if (basePrice <= 0)
        {
            MessageBox::Show("Base price must be greater than 0.");
            return;
        }
    }
    catch (...)
    {
        MessageBox::Show("Invalid base price.");
        return;
    }

    OdbcConnection^ con = ODBCHelper::GetConnection();

    try
    {
        con->Open();
        OdbcTransaction^ tx = con->BeginTransaction();

        try
        {
            int fromCityId = GetOrCreateCityId_Airline(con, tx, fromCity);
            int toCityId = GetOrCreateCityId_Airline(con, tx, toCity);

            // route
            int routeId = GetOrCreateRouteId_Airline(con, tx, fromCityId, toCityId);

            // insert flight
            String^ qInsFlight =
                "INSERT INTO flights (flight_code, route_id, base_price) "
                "VALUES (?, ?, ?)";

            OdbcCommand^ cmd = gcnew OdbcCommand(qInsFlight, con, tx);
            cmd->Parameters->AddWithValue("@p1", flightCode);
            cmd->Parameters->AddWithValue("@p2", routeId);
            cmd->Parameters->AddWithValue("@p3", basePrice);

            cmd->ExecuteNonQuery();

            tx->Commit();
        }
        catch (Exception^)
        {
            tx->Rollback();
            throw;
        }

        MessageBox::Show("Flight Added Successfully");

        LoadFlights();

        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
        textBox4->Clear();
    }
    catch (OdbcException^ ex)
    {
        // ORA-00001 unique violation: flight_code unique OR route unique
        if (ex->Message->Contains("ORA-00001"))
            MessageBox::Show("Duplicate record! Flight Code already exists (or route unique constraint hit).");
        else
            MessageBox::Show("Database Error:\n" + ex->Message);
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error:\n" + ex->Message);
    }
    finally
    {
        if (con != nullptr && con->State == ConnectionState::Open)
            con->Close();
    }
}

// =====================
// NAVIGATION BUTTONS
// =====================

// Home
System::Void Flight::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    Dashboard^ f = gcnew Dashboard();
    this->Hide();
    f->Show();
}

// Flights (refresh)
System::Void Flight::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    LoadFlights();
}

// Passengers
System::Void Flight::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    Passengers^ f = gcnew Passengers();
    this->Hide();
    f->Show();
}

// Booking
System::Void Flight::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    Booking^ f = gcnew Booking();
    this->Hide();
    f->Show();
}

// Contact
System::Void Flight::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    ContactUs^ f = gcnew ContactUs();
    this->Hide();
    f->Show();
}
