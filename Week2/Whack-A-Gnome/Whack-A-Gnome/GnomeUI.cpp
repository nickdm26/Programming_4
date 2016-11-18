#include "GnomeUI.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WhackAGnome::GnomeUI form;
	Application::Run(%form);
}

