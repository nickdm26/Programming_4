#include "Nicks_RougeLike.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RogueLike::Nicks_RougeLike form;
	Application::Run(%form);
}