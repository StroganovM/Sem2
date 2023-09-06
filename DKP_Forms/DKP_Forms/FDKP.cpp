#include "FDKP.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace DKPForms;
[STAThread]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew FDKP());
}

