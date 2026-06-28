#include "Signup.h"
#include "Login.h"
#include "ODBCHelper.h"

using namespace AirLineManagementSystem;
using namespace System;
using namespace System::Data;
using namespace System::Data::Odbc;
using namespace System::Windows::Forms;
using namespace System::Text::RegularExpressions;

System::Void Signup::Signup_Load(System::Object^ sender, System::EventArgs^ e)
{
    comboBox1->Items->Clear();
    comboBox1->Items->Add("Male");
    comboBox1->Items->Add("Female");
    comboBox1->Items->Add("Other");
    comboBox1->SelectedIndex = -1;

    // optional: restrict typing
    comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
}

static bool IsValidEmail(String^ email)
{
    if (String::IsNullOrWhiteSpace(email)) return false;
    // simple email regex (enough for UI validation)
    return Regex::IsMatch(email, "^[^\\s@]+@[^\\s@]+\\.[^\\s@]+$");
}

System::Void Signup::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ fullName = textBox1->Text->Trim();
    String^ email = textBox2->Text->Trim();
    String^ pass = textBox3->Text; // do not trim passwords
    String^ gender = comboBox1->Text->Trim();

    // ---------------------------
    // Validation
    // ---------------------------
    if (fullName == "" || email == "" || pass == "" || gender == "")
    {
        MessageBox::Show("Please fill all fields.");
        return;
    }

    if (!IsValidEmail(email))
    {
        MessageBox::Show("Please enter a valid email address.");
        return;
    }

    // ---------------------------
    // DB Queries (Oracle script ke mutabiq)
    // persons trigger person_id auto generate karega
    // persons.email UNIQUE => ORA-00001 ayega if duplicate
    // ---------------------------
    String^ insertPerson =
        "INSERT INTO persons (full_name, email, password, gender) VALUES (?, ?, ?, ?)";

    String^ getId =
        "SELECT person_id FROM persons WHERE email = ?";

    String^ insertUser =
        "INSERT INTO app_users (user_id) VALUES (?)";

    OdbcConnection^ con = ODBCHelper::GetConnection();

    try
    {
        con->Open();
        OdbcTransaction^ tx = con->BeginTransaction();

        try
        {
            // 1) Insert into persons
            OdbcCommand^ cmd1 = gcnew OdbcCommand(insertPerson, con, tx);
            cmd1->Parameters->Add("@p1", OdbcType::VarChar)->Value = fullName;
            cmd1->Parameters->Add("@p2", OdbcType::VarChar)->Value = email;
            cmd1->Parameters->Add("@p3", OdbcType::VarChar)->Value = pass;
            cmd1->Parameters->Add("@p4", OdbcType::VarChar)->Value = gender;
            cmd1->ExecuteNonQuery();

            // 2) Get generated person_id (by email, same tx)
            OdbcCommand^ cmd2 = gcnew OdbcCommand(getId, con, tx);
            cmd2->Parameters->Add("@p1", OdbcType::VarChar)->Value = email;
            Object^ idObj = cmd2->ExecuteScalar();

            if (idObj == nullptr)
                throw gcnew Exception("Signup failed: person_id not found.");

            int pid = Convert::ToInt32(idObj);

            // 3) Insert into app_users
            OdbcCommand^ cmd3 = gcnew OdbcCommand(insertUser, con, tx);
            cmd3->Parameters->Add("@p1", OdbcType::Int)->Value = pid;
            cmd3->ExecuteNonQuery();

            tx->Commit();
        }
        catch (...)
        {
            tx->Rollback();
            throw;
        }

        MessageBox::Show("Signup Successful!");

        // clear UI
        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
        comboBox1->SelectedIndex = -1;

        // go to Login
        Login^ lg = gcnew Login();
        this->Hide();
        lg->Show();
        // optional: this->Close();  // agar aap Signup ko permanently close karna chahte ho
    }
    catch (OdbcException^ ex)
    {
        if (ex->Message->Contains("ORA-00001"))
        {
            MessageBox::Show("Email already exists. Try another email.");
        }
        else
        {
            MessageBox::Show("DB Error:\n" + ex->Message);
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error:\n" + ex->Message);
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

System::Void Signup::linkLabel1_LinkClicked(
    System::Object^ sender,
    System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
{
    Login^ lg = gcnew Login();
    this->Hide();
    lg->Show();
    // optional: this->Close();
}
