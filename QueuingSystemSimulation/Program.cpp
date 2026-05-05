#include "HomePage.h"
#include "Queue.h"
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace QueuingSystemSimulation;

[STAThreadAttribute]
int main(cli::array<System::String^>^ args) {
	FreeConsole();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HomePage());
    return 0;
}
