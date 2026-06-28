#pragma once

using namespace System;
using namespace System::Data::Odbc;

public ref class ODBCHelper
{
public:
    static OdbcConnection^ GetConnection()
    {
        String^ conStr = "DSN=AIRLINE_MANAGEMENT_SYSTEM;Uid=AIRLINE_MANAGEMENT_SYSTEM;Pwd=airline0000;";
     

        return gcnew OdbcConnection(conStr);
    }
};
