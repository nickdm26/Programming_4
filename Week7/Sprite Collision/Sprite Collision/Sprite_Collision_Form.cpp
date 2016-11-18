#include "Sprite_Collision_Form.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SpriteCollision::Sprite_Collision_Form form;
	Application::Run(%form);

}