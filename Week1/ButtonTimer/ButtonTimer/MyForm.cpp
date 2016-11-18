#include "MyForm.h"
#include <iostream>;

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ButtonTimer::MyForm form;
	Application::Run(%form);

}