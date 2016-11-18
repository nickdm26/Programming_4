#include "MyForm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Knight_Project::MyForm form;
	Application::Run(%form);

}
