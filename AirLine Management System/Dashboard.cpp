#include "Dashboard.h"
#include "Flight.h"
#include "Passengers.h"
#include "Booking.h"
#include "ContactUs.h"
#include "AppSession.h"
#include "ODBCHelper.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;

namespace AirLineManagementSystem
{
    bool Dashboard::IsAdminOrStaff()
    {
        return (AppSession::CurrentRole != nullptr &&
            (AppSession::CurrentRole->Equals("Admin", StringComparison::OrdinalIgnoreCase) ||
                AppSession::CurrentRole->Equals("Staff", StringComparison::OrdinalIgnoreCase)));
    }

    void Dashboard::LoadDashboardStats()
    {
        // Aapke labels (as per your form):
        // label2 -> Total Flights
        // label3 -> Total Customers (App Users)
        // label5 -> Total Bookings
        // label7 -> Earned (SUM price_at_booking)

        this->label2->Text = "0";
        this->label3->Text = "0";
        this->label5->Text = "0";
        this->label7->Text = "0";

        OdbcConnection^ con = ODBCHelper::GetConnection();

        try
        {
            con->Open();

            // 1) Total Flights
            {
                OdbcCommand^ cmd = gcnew OdbcCommand("SELECT COUNT(*) FROM flights", con);
                Object^ v = cmd->ExecuteScalar();
                if (v != nullptr && v != DBNull::Value)
                    this->label2->Text = v->ToString();
            }

            // 2) Total Customers (App Users)
            // (Agar aap ALL persons dikhana chahen: persons table use kar lena)
            {
                OdbcCommand^ cmd = gcnew OdbcCommand("SELECT COUNT(*) FROM app_users", con);
                Object^ v = cmd->ExecuteScalar();
                if (v != nullptr && v != DBNull::Value)
                    this->label3->Text = v->ToString();
            }

            // 3) Bookings + Earned
            if (IsAdminOrStaff())
            {
                // Admin/Staff: all bookings
                {
                    OdbcCommand^ cmd = gcnew OdbcCommand("SELECT COUNT(*) FROM bookings", con);
                    Object^ v = cmd->ExecuteScalar();
                    if (v != nullptr && v != DBNull::Value)
                        this->label5->Text = v->ToString();
                }
                {
                    OdbcCommand^ cmd = gcnew OdbcCommand(
                        "SELECT NVL(SUM(price_at_booking), 0) FROM bookings", con);

                    Object^ v = cmd->ExecuteScalar();
                    if (v != nullptr && v != DBNull::Value)
                        this->label7->Text = v->ToString();
                }
            }
            else
            {
                // User: only own bookings (bookings.user_id)
                {
                    OdbcCommand^ cmd = gcnew OdbcCommand(
                        "SELECT COUNT(*) FROM bookings WHERE user_id = ?", con);

                    cmd->Parameters->Add("@p1", OdbcType::Int)->Value = AppSession::CurrentPersonId;

                    Object^ v = cmd->ExecuteScalar();
                    if (v != nullptr && v != DBNull::Value)
                        this->label5->Text = v->ToString();
                }
                {
                    OdbcCommand^ cmd = gcnew OdbcCommand(
                        "SELECT NVL(SUM(price_at_booking), 0) FROM bookings WHERE user_id = ?", con);

                    cmd->Parameters->Add("@p1", OdbcType::Int)->Value = AppSession::CurrentPersonId;

                    Object^ v = cmd->ExecuteScalar();
                    if (v != nullptr && v != DBNull::Value)
                        this->label7->Text = v->ToString();
                }
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Dashboard stats error:\n" + ex->Message);
        }
        finally
        {
            try
            {
                if (con != nullptr && con->State == ConnectionState::Open)
                    con->Close();
            }
            catch (...) {}
        }
    }

    System::Void Dashboard::Dashboard_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // User => hide panel3/panel4, Admin/Staff => show
        if (IsAdminOrStaff())
        {
            this->panel3->Visible = true;
            this->panel4->Visible = true;
        }
        else
        {
            this->panel3->Visible = false;
            this->panel4->Visible = false;
        }

        LoadDashboardStats();
    }

    System::Void Dashboard::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadDashboardStats(); // refresh on Home click
    }

    System::Void Dashboard::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Flight^ f = gcnew Flight();
        this->Hide();
        f->Show();
    }

    System::Void Dashboard::button3_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Passengers^ p = gcnew Passengers();
        this->Hide();
        p->Show();
    }

    System::Void Dashboard::button4_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Booking^ b = gcnew Booking();
        this->Hide();
        b->Show();
    }

    System::Void Dashboard::button5_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ContactUs^ c = gcnew ContactUs();
        this->Hide();
        c->Show();
    }
}
