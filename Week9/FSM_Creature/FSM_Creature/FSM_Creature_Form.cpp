#include "FSM_Creature_Form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FSM_Creature::FSM_Creature_Form form;
	Application::Run(%form);
}

