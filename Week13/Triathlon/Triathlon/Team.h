#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Team
{
private:
String^ Swimmer;
String^ Cyclist;
String^ Runner;

public:
	Team(String^ newSwimmer, String^ newCyclist, String^ newRunner);
	String^ ToString() override { return "Swimmer: " + Swimmer + " Cyclist: " + Cyclist + " Runner: " + Runner; }
};

