#include "ContactUs.h"
#include "Dashboard.h"
#include "Flight.h"
#include "Passengers.h"
#include "Booking.h"
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
    // FORM LOAD
    // =====================
    System::Void ContactUs::ContactUs_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // ✅ User => hide panel3/panel4, Admin/Staff => show
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
    }

    // =====================
    // SEND BUTTON (STORE DATA)
    // =====================
    System::Void ContactUs::button6_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ name = textBox1->Text->Trim();
        String^ subject = textBox2->Text->Trim();
        String^ email = textBox3->Text->Trim();
        String^ message = textBox4->Text->Trim();

        if (String::IsNullOrWhiteSpace(name) ||
            String::IsNullOrWhiteSpace(subject) ||
            String::IsNullOrWhiteSpace(email) ||
            String::IsNullOrWhiteSpace(message))
        {
            MessageBox::Show("Please fill all fields.");
            return;
        }

        OdbcConnection^ con = ODBCHelper::GetConnection();

        String^ query =
            "INSERT INTO contact_messages (name, subject, email, message) "
            "VALUES (?, ?, ?, ?)";

        try
        {
            con->Open();

            OdbcCommand^ cmd = gcnew OdbcCommand(query, con);

            cmd->Parameters->Add("@p1", OdbcType::VarChar, 100)->Value = name;
            cmd->Parameters->Add("@p2", OdbcType::VarChar, 150)->Value = subject;
            cmd->Parameters->Add("@p3", OdbcType::VarChar, 150)->Value = email;

            // message is CLOB in Oracle; ODBC usually works fine with VarChar for normal text
            cmd->Parameters->Add("@p4", OdbcType::VarChar)->Value = message;

            cmd->ExecuteNonQuery();

            MessageBox::Show("Message Sent Successfully!");

            textBox1->Clear();
            textBox2->Clear();
            textBox3->Clear();
            textBox4->Clear();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error sending message:\n" + ex->Message);
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

    // =====================
    // NAVIGATION
    // =====================

    // Home
    System::Void ContactUs::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Dashboard^ d = gcnew Dashboard();
        d->ShowDialog();
        this->Close();
    }

    // Flights
    System::Void ContactUs::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Flight^ f = gcnew Flight();
        f->ShowDialog();
        this->Close();
    }

    // Passengers
    System::Void ContactUs::button3_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Passengers^ p = gcnew Passengers();
        p->ShowDialog();
        this->Close();
    }

    // Booking
    System::Void ContactUs::button4_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        Booking^ b = gcnew Booking();
        b->ShowDialog();
        this->Close();
    }

    // Exit
    System::Void ContactUs::button5_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }
}
