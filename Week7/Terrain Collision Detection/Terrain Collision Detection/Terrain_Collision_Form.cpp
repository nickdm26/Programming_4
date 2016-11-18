#include "Terrain_Collision_Form.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TerrainCollisionDetection::Terrain_Collision_Form form;
	Application::Run(%form);
}