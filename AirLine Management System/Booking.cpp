#include "Booking.h"
#include "Dashboard.h"
#include "Flight.h"
#include "Passengers.h"
#include "ContactUs.h"
#include "ODBCHelper.h"
#include "AppSession.h"

using namespace AirLineManagementSystem;
using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;

namespace AirLineManagementSystem
{
    // =====================
    // Grid in panel8
    // =====================
    void Booking::EnsureBookingsGrid()
    {
        if (bookingsGrid != nullptr) return;

        bookingsGrid = gcnew DataGridView();
        bookingsGrid->Dock = DockStyle::Fill;
        bookingsGrid->ReadOnly = true;
        bookingsGrid->AllowUserToAddRows = false;
        bookingsGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        bookingsGrid->MultiSelect = false;
        bookingsGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

        panel8->Controls->Clear();
        panel8->Controls->Add(bookingsGrid);
    }

    // =====================
    // comboBox1 = Flights (ONLY code)
    // =====================
    void Booking::LoadFlights()
    {
        OdbcConnection^ con = ODBCHelper::GetConnection();

        String^ q =
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
            DataTable^ dt = gcnew DataTable();
            OdbcDataAdapter^ da = gcnew OdbcDataAdapter(q, con);
            da->Fill(dt);

            comboBox1->DataSource = dt;
            comboBox1->DisplayMember = "flight_code"; // ONLY CODE
            comboBox1->ValueMember = "flight_id";

            if (dt->Rows->Count > 0) comboBox1->SelectedIndex = 0;

            // FROM/TO combos should be list style (optional but good)
            comboBox4->DropDownStyle = ComboBoxStyle::DropDownList;
            comboBox5->DropDownStyle = ComboBoxStyle::DropDownList;

            // update route + price at start
            ShowSelectedFlightRoute();
            label9->Text = GetSelectedFlightPrice().ToString("0.##");
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
    // comboBox2 = Customers/Passengers
    // Admin/Staff => all app_users
    // User => only logged-in user
    // =====================
    void Booking::LoadCustomers()
    {
        OdbcConnection^ con = ODBCHelper::GetConnection();

        String^ qAll =
            "SELECT p.person_id AS user_id, p.full_name "
            "FROM persons p "
            "JOIN app_users au ON au.user_id = p.person_id "
            "ORDER BY p.full_name";

        String^ qMine =
            "SELECT p.person_id AS user_id, p.full_name "
            "FROM persons p "
            "WHERE p.person_id = ?";

        try
        {
            DataTable^ dt = gcnew DataTable();

            if (AppSession::IsAdminOrStaff())
            {
                OdbcDataAdapter^ da = gcnew OdbcDataAdapter(qAll, con);
                da->Fill(dt);
                comboBox2->Enabled = true;
            }
            else
            {
                OdbcCommand^ cmd = gcnew OdbcCommand(qMine, con);
                cmd->Parameters->Add("@p1", OdbcType::Int)->Value = AppSession::CurrentPersonId;

                OdbcDataAdapter^ da = gcnew OdbcDataAdapter(cmd);
                da->Fill(dt);

                comboBox2->Enabled = false; // user ko lock
            }

            comboBox2->DataSource = dt;
            comboBox2->DisplayMember = "full_name";
            comboBox2->ValueMember = "user_id";

            if (dt->Rows->Count > 0) comboBox2->SelectedIndex = 0;

            if (!AppSession::IsAdminOrStaff() && AppSession::CurrentPersonId > 0)
                comboBox2->SelectedValue = AppSession::CurrentPersonId;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error loading customers:\n" + ex->Message);
        }
        finally
        {
            if (con != nullptr && con->State == ConnectionState::Open)
                con->Close();
        }
    }

    // =====================
    // comboBox3 = Seat No (1..300)
    // =====================
    void Booking::LoadSeatNumbers()
    {
        comboBox3->Items->Clear();
        for (int s = 1; s <= 300; s++)
            comboBox3->Items->Add(s.ToString());

        if (comboBox3->Items->Count > 0)
            comboBox3->SelectedIndex = 0;
    }

    // =====================
    // panel8 = bookings grid
    // Admin/Staff => all bookings
    // User => only own bookings
    // =====================
    void Booking::LoadBookingsGrid()
    {
        EnsureBookingsGrid();

        OdbcConnection^ con = ODBCHelper::GetConnection();

        String^ qAll =
            "SELECT "
            "  b.booking_id, "
            "  fl.flight_code, "
            "  p.full_name, "
            "  b.seat_no, "
            "  b.travel_date, "
            "  b.price_at_booking "
            "FROM bookings b "
            "JOIN flights fl ON fl.flight_id = b.flight_id "
            "JOIN persons p ON p.person_id = b.user_id "
            "ORDER BY b.booking_id DESC";

        String^ qMine =
            "SELECT "
            "  b.booking_id, "
            "  fl.flight_code, "
            "  p.full_name, "
            "  b.seat_no, "
            "  b.travel_date, "
            "  b.price_at_booking "
            "FROM bookings b "
            "JOIN flights fl ON fl.flight_id = b.flight_id "
            "JOIN persons p ON p.person_id = b.user_id "
            "WHERE b.user_id = ? "
            "ORDER BY b.booking_id DESC";

        try
        {
            DataTable^ dt = gcnew DataTable();

            if (AppSession::IsAdminOrStaff())
            {
                OdbcDataAdapter^ da = gcnew OdbcDataAdapter(qAll, con);
                da->Fill(dt);
            }
            else
            {
                OdbcCommand^ cmd = gcnew OdbcCommand(qMine, con);
                cmd->Parameters->Add("@p1", OdbcType::Int)->Value = AppSession::CurrentPersonId;

                OdbcDataAdapter^ da = gcnew OdbcDataAdapter(cmd);
                da->Fill(dt);
            }

            bookingsGrid->DataSource = dt;

            if (bookingsGrid->Columns->Count > 0)
            {
                bookingsGrid->Columns["booking_id"]->HeaderText = "Booking ID";
                bookingsGrid->Columns["flight_code"]->HeaderText = "Flight";
                bookingsGrid->Columns["full_name"]->HeaderText = "Passenger";
                bookingsGrid->Columns["seat_no"]->HeaderText = "Seat No";
                bookingsGrid->Columns["travel_date"]->HeaderText = "Travel Date";
                bookingsGrid->Columns["price_at_booking"]->HeaderText = "Price";
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error loading bookings:\n" + ex->Message);
        }
        finally
        {
            if (con != nullptr && con->State == ConnectionState::Open)
                con->Close();
        }
    }

    // =====================
    // Price helper (from selected flight row)
    // =====================
    double Booking::GetSelectedFlightPrice()
    {
        try
        {
            if (comboBox1->SelectedItem == nullptr) return 0;

            DataRowView^ drv = dynamic_cast<DataRowView^>(comboBox1->SelectedItem);
            if (drv == nullptr) return 0;

            return Convert::ToDouble(drv["base_price"]);
        }
        catch (...) { return 0; }
    }

    // =====================
    // FROM/TO helper (from selected flight row)
    // comboBox4 = FROM, comboBox5 = TO
    // =====================
    void Booking::ShowSelectedFlightRoute()
    {
        try
        {
            comboBox4->DataSource = nullptr;
            comboBox5->DataSource = nullptr;
            comboBox4->Items->Clear();
            comboBox5->Items->Clear();

            if (comboBox1->SelectedItem == nullptr) return;

            DataRowView^ drv = dynamic_cast<DataRowView^>(comboBox1->SelectedItem);
            if (drv == nullptr) return;

            String^ fromCity = Convert::ToString(drv["from_city"]);
            String^ toCity = Convert::ToString(drv["to_city"]);

            comboBox4->Items->Add(fromCity);
            comboBox5->Items->Add(toCity);

            comboBox4->SelectedIndex = 0;
            comboBox5->SelectedIndex = 0;
        }
        catch (...) {}
    }

    // =====================
    // FORM LOAD
    // =====================
    System::Void Booking::Booking_Load(System::Object^ sender, System::EventArgs^ e)
    {
        if (AppSession::IsAdminOrStaff())
        {
            panel3->Visible = true;
            panel4->Visible = true;
        }
        else
        {
            panel3->Visible = false;
            panel4->Visible = false;
        }

        EnsureBookingsGrid();
        LoadFlights();
        LoadCustomers();
        LoadSeatNumbers();

        label9->Text = GetSelectedFlightPrice().ToString("0.##");
        ShowSelectedFlightRoute();

        LoadBookingsGrid();
    }

    // =====================
    // Flight changed => update FROM/TO + Price
    // =====================
    System::Void Booking::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        ShowSelectedFlightRoute();
        label9->Text = GetSelectedFlightPrice().ToString("0.##");
    }

    System::Void Booking::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
    {
        // no action
    }

    // =====================
    // CONFIRM BOOKING
    // =====================
    System::Void Booking::button6_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (!AppSession::IsAdminOrStaff() && AppSession::CurrentPersonId > 0)
            comboBox2->SelectedValue = AppSession::CurrentPersonId;

        if (comboBox1->SelectedValue == nullptr ||
            comboBox2->SelectedValue == nullptr ||
            comboBox3->SelectedItem == nullptr)
        {
            MessageBox::Show("Please select Flight Code, Passenger and Seat No.");
            return;
        }

        int flightId = Convert::ToInt32(comboBox1->SelectedValue);
        int userId = Convert::ToInt32(comboBox2->SelectedValue);
        int seatNo = Convert::ToInt32(comboBox3->SelectedItem->ToString());
        DateTime travelDate = dateTimePicker1->Value.Date;

        double priceAtBooking = GetSelectedFlightPrice();
        label9->Text = priceAtBooking.ToString("0.##");

        if (priceAtBooking <= 0)
        {
            MessageBox::Show("Invalid price. Please select a valid flight.");
            return;
        }

        OdbcConnection^ con = ODBCHelper::GetConnection();

        try
        {
            con->Open();
            OdbcTransaction^ tx = con->BeginTransaction();

            try
            {
                String^ qIns =
                    "INSERT INTO bookings (flight_id, user_id, seat_no, travel_date, price_at_booking) "
                    "VALUES (?, ?, ?, ?, ?)";

                OdbcCommand^ cmd = gcnew OdbcCommand(qIns, con, tx);
                cmd->Parameters->Add("@p1", OdbcType::Int)->Value = flightId;
                cmd->Parameters->Add("@p2", OdbcType::Int)->Value = userId;
                cmd->Parameters->Add("@p3", OdbcType::Int)->Value = seatNo;
                cmd->Parameters->Add("@p4", OdbcType::Date)->Value = travelDate;
                cmd->Parameters->Add("@p5", OdbcType::Double)->Value = priceAtBooking;

                cmd->ExecuteNonQuery();
                tx->Commit();
            }
            catch (OdbcException^ ex)
            {
                tx->Rollback();

                if (ex->Message->Contains("ORA-00001"))
                {
                    MessageBox::Show("This seat is already booked for selected flight & date.\nChoose another seat.");
                }
                else
                {
                    MessageBox::Show("Database Error:\n" + ex->Message);
                }
                return;
            }
            catch (Exception^ ex)
            {
                tx->Rollback();
                MessageBox::Show("Error:\n" + ex->Message);
                return;
            }

            MessageBox::Show("Booking Confirmed!");
            LoadBookingsGrid();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error:\n" + ex->Message);
        }
        finally
        {
            try { if (con != nullptr && con->State == ConnectionState::Open) con->Close(); }
            catch (...) {}
        }
    }

    System::Void Booking::panel8_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
    {
    }

    // =====================
    // NAVIGATION
    // =====================
    System::Void Booking::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Dashboard^ d = gcnew Dashboard();
        d->ShowDialog();
        this->Close();
    }

    System::Void Booking::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Flight^ f = gcnew Flight();
        f->ShowDialog();
        this->Close();
    }

    System::Void Booking::button3_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Passengers^ p = gcnew Passengers();
        p->ShowDialog();
        this->Close();
    }

    System::Void Booking::button4_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadBookingsGrid();
    }

    System::Void Booking::button5_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        ContactUs^ c = gcnew ContactUs();
        c->ShowDialog();
        this->Close();
    }
}
