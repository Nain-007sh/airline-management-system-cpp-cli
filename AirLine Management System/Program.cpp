#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AirLineManagementSystem;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Login());
    return 0;
}
