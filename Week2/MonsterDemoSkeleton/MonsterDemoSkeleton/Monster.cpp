#include "Monster.h"


Monster::Monster(String^ Mname)
{
	name = Mname;
	
}

void Monster::Speak()
{
	MessageBox::Show("I am a Monster! Roar! My name is " + name);
}