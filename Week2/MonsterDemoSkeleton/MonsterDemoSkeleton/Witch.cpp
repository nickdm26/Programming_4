#include "Witch.h"


Witch::Witch(String^ Wname)
{
	name = Wname;
}

void Witch::Speak()
{
	MessageBox::Show("I am a Witch! Hehehe! My name is " + name);
}
