#include "pch.h"

#include <G4String.hh>
#include <G4RichTrajectory.hh>
#include <G4RichTrajectoryPoint.hh>
#include <G4SystemOfUnits.hh>

#include "Util.hh"

double Util::To_NS(G4String str)
{
    std::stringstream ss(str);
    double time;
    std::string unit;
    ss >> time >> unit;
    if (unit == "s")
    {
        time *= 1e9;
    }
    else if (unit == "ms")
    {
        time *= 1e6;
    }
    else if (unit == "us")
    {
        time *= 1e3;
    }
    else if (unit == "ps")
    {
        time *= 1e-3;
    }
    return time;
}

double Util::To_MeV(G4String str)
{
    std::stringstream ss(str);
    G4double energy;
    std::string unit;
    ss >> energy >> unit;
    if (unit == "eV")
    {
        energy *= 1e-6;
    }
    else if (unit == "keV")
    {
        energy *= 1e-3;
    }
    else if (unit == "GeV")
    {
        energy *= 1e3;
    }
    else if (unit == "TeV")
    {
        energy *= 1e6;
    }
    else if (unit == "PeV")
    {
        energy *= 1e9;
    }
    return energy;
}

char* Util::GetCopiedStringPtr(std::string str)
{
    char* ptr = new char[str.length() + 1];
    std::strcpy(ptr, str.c_str());
    return ptr;
}