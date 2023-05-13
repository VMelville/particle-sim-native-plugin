#pragma once

#include <G4ThreeVector.hh>

struct ThreeVector
{
public:
    ThreeVector();
    ThreeVector(double x, double y, double z);
    ThreeVector(G4ThreeVector g4vec);
    ~ThreeVector();

    G4ThreeVector AsG4ThreeVector();

    double x;
    double y;
    double z;
};
