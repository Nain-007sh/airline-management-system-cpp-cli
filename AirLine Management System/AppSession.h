#pragma once
using namespace System;

namespace AirLineManagementSystem
{
    public ref class AppSession abstract sealed
    {
    public:
        static int    CurrentPersonId = 0;
        static String^ CurrentName = "";
        static String^ CurrentEmail = "";
        static String^ CurrentRole = "User";

        static bool IsAdminOrStaff()
        {
            if (CurrentRole == nullptr) return false;
            return (CurrentRole->Equals("Admin", StringComparison::OrdinalIgnoreCase) ||
                CurrentRole->Equals("Staff", StringComparison::OrdinalIgnoreCase));
        }
    };
}
