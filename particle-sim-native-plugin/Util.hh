#pragma once

#include <G4String.hh>

class Util
{
public:
	static double To_NS(G4String str);
	static double To_MeV(G4String str);
	static char* GetCopiedStringPtr(std::string str);
};
