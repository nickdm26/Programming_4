#include "Directional_Sprites_Bounds.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Directional_Sprites_With_Bounds::Directional_Sprites_Bounds form;
	Application::Run(%form);

}
