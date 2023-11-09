#include "lab4_main_form.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	lab4::lab4_main_form form;
	Application::Run(% form);
}