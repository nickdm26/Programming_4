#include "MyForm.h"
#include <iostream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Prac2::MyForm form;
	Application::Run(%form);
}
