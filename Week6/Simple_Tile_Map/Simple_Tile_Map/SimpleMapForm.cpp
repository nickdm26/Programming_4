#include "SimpleMapForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Simple_Tile_Map::SimpleMapForm form;
	Application::Run(%form);
}

