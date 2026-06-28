#include "Passengers.h"
#include "Dashboard.h"
#include "ODBCHelper.h"
#include "Flight.h"
#include "Booking.h"
#include "ContactUs.h"

#include <vector>

using namespace AirLineManagementSystem;
using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;

namespace AirLineManagementSystem
{
    // =====================
    // DSA: Passenger DTO (Data Structure element)
    // =====================
    public ref class PassengerDTO
    {
    public:
        property int UserId;
        property String^ FullName;
        property String^ Email;
        property String^ Gender;
        property DateTime CreatedAt;
    };

    // =====================
    // LOAD PASSENGERS (APP USERS ONLY) - SAME LOGIC, DSA APPLIED
    // =====================
    void Passengers::LoadPassengers()
    {
        OdbcConnection^ con = ODBCHelper::GetConnection();

        String^ query =
            "SELECT "
            "  p.person_id AS user_id, "
            "  p.full_name, "
            "  p.email, "
            "  p.gender, "
            "  p.created_at "
            "FROM persons p "
            "JOIN app_users au ON au.user_id = p.person_id "
            "ORDER BY p.person_id DESC";

        try
        {
            // DSA container
            std::vector<PassengerDTO^> passengers;

            con->Open();
            OdbcCommand^ cmd = gcnew OdbcCommand(query, con);
            OdbcDataReader^ dr = cmd->ExecuteReader();

            while (dr->Read())
            {
                PassengerDTO^ p = gcnew PassengerDTO();
                p->UserId = Convert::ToInt32(dr["user_id"]);
                p->FullName = dr["full_name"]->ToString();
                p->Email = dr["email"]->ToString();
                p->Gender = dr["gender"]->ToString();
                p->CreatedAt = Convert::ToDateTime(dr["created_at"]);

                passengers.push_back(p);
            }
            dr->Close();

            // Convert DSA vector -> BindingList (for grid binding)
            BindingList<PassengerDTO^>^ list = gcnew BindingList<PassengerDTO^>();
            for (auto item : passengers) list->Add(item);

            dgv->DataSource = list;

            // Header texts (same as before)
            if (dgv->Columns->Count > 0)
            {
                dgv->Columns["UserId"]->HeaderText = "User ID";
                dgv->Columns["FullName"]->HeaderText = "Full Name";
                dgv->Columns["Email"]->HeaderText = "Email";
                dgv->Columns["Gender"]->HeaderText = "Gender";
                dgv->Columns["CreatedAt"]->HeaderText = "Created At";
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error loading passengers:\n" + ex->Message);
        }
        finally
        {
            if (con != nullptr && con->State == ConnectionState::Open)
                con->Close();
        }
    }

    // =====================
    // FORM LOAD
    // =====================
    System::Void Passengers::Passengers_Load(System::Object^ sender, System::EventArgs^ e)
    {
        dgv = gcnew DataGridView();
        panel7->Controls->Clear();
        panel7->Controls->Add(dgv);

        dgv->Dock = DockStyle::Fill;
        dgv->ReadOnly = true;
        dgv->AllowUserToAddRows = false;
        dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dgv->MultiSelect = false;
        dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

        LoadPassengers();
    }

    // =====================
    // NAVIGATION BUTTONS (same)
    // =====================

    System::Void Passengers::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Dashboard^ d = gcnew Dashboard();
        this->Hide();
        d->Show();
    }

    System::Void Passengers::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Flight^ f = gcnew Flight();
        this->Hide();
        f->Show();
    }

    System::Void Passengers::button3_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadPassengers();
    }

    System::Void Passengers::button4_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Booking^ b = gcnew Booking();
        this->Hide();
        b->Show();
    }

    System::Void Passengers::button5_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ContactUs^ c = gcnew ContactUs();
        this->Hide();
        c->Show();
    }
}
 