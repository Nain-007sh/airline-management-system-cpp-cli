#include "Login.h"
#include "Signup.h"
#include "Dashboard.h"
#include "ContactUs.h"
#include "ODBCHelper.h"
#include "AppSession.h"

using namespace AirLineManagementSystem;
using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;

System::Void Login::Login_Load(System::Object^ sender, System::EventArgs^ e)
{
    textBox1->Clear();
    textBox2->Clear();
    textBox2->UseSystemPasswordChar = true;
}

System::Void Login::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ email = textBox1->Text->Trim();
    String^ pass = textBox2->Text;

    if (String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(pass))
    {
        MessageBox::Show("Please enter Email and Password");
        return;
    }

    OdbcConnection^ con = ODBCHelper::GetConnection();

    // 1) Verify login from persons
    String^ qPerson =
        "SELECT person_id, full_name, email "
        "FROM persons "
        "WHERE email = ? AND password = ?";

    // 2) Check role from accounts (Admin/Staff)
    String^ qRole =
        "SELECT role FROM accounts WHERE account_id = ?";

    // 3) Check normal user from app_users
    String^ qIsUser =
        "SELECT user_id FROM app_users WHERE user_id = ?";

    try
    {
        con->Open();

        // ==========================
        // (1) LOGIN VERIFY (persons)
        // ==========================
        OdbcCommand^ cmdPerson = gcnew OdbcCommand(qPerson, con);
        cmdPerson->Parameters->Add("@p1", OdbcType::VarChar)->Value = email;
        cmdPerson->Parameters->Add("@p2", OdbcType::VarChar)->Value = pass;

        OdbcDataReader^ dr = cmdPerson->ExecuteReader();

        if (!dr->Read())
        {
            dr->Close();
            MessageBox::Show("Invalid Email or Password");
            return;
        }

        int pid = Convert::ToInt32(dr["person_id"]);
        String^ fullName = dr["full_name"]->ToString();
        String^ em = dr["email"]->ToString();
        dr->Close();

        // ==========================
        // (2) ROLE DECISION
        // ==========================
        String^ role = nullptr;

        // Check accounts table first (Admin/Staff)
        OdbcCommand^ cmdRole = gcnew OdbcCommand(qRole, con);
        cmdRole->Parameters->Add("@p1", OdbcType::Int)->Value = pid;

        Object^ roleObj = cmdRole->ExecuteScalar();
        if (roleObj != nullptr && roleObj != DBNull::Value)
        {
            role = roleObj->ToString()->Trim(); // "Admin" or "Staff"
        }
        else
        {
            // If not in accounts, must be in app_users
            OdbcCommand^ cmdUser = gcnew OdbcCommand(qIsUser, con);
            cmdUser->Parameters->Add("@p1", OdbcType::Int)->Value = pid;

            Object^ userObj = cmdUser->ExecuteScalar();
            if (userObj != nullptr && userObj != DBNull::Value)
                role = "User";
        }

        if (String::IsNullOrWhiteSpace(role))
        {
            MessageBox::Show("Account not linked as App User or Staff/Admin. Contact admin.");
            return;
        }

        // ==========================
        // (3) SAVE SESSION (GLOBAL)
        // ==========================
        AppSession::CurrentPersonId = pid;
        AppSession::CurrentName = fullName;
        AppSession::CurrentEmail = em;
        AppSession::CurrentRole = role;

        // Debug / confirmation
        MessageBox::Show("Login Successful\nName: " + fullName + "\nRole: " + role);

        // ==========================
        // (4) OPEN DASHBOARD
        // ==========================
        Dashboard^ f = gcnew Dashboard();
        this->Hide();
        f->Show();
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

System::Void Login::linkLabel1_LinkClicked(
    System::Object^ sender,
    System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
    Signup^ s = gcnew Signup();
    this->Hide();
    s->Show();
}

System::Void Login::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
}
