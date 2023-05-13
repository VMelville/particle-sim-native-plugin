#include "pch.h"

#include "ThreeVector.hh"

ThreeVector::ThreeVector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

ThreeVector::ThreeVector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

ThreeVector::ThreeVector(G4ThreeVector g4vec)
{
    this->x = g4vec.getX();
    this->y = g4vec.getY();
    this->z = g4vec.getZ();
}

ThreeVector::~ThreeVector()
{
}

G4ThreeVector ThreeVector::AsG4ThreeVector()
{
    return G4ThreeVector(x, y, z);
}

