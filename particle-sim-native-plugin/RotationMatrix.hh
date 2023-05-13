#pragma once

#include <G4RotationMatrix.hh>

struct RotationMatrix
{
public:
    RotationMatrix();
    RotationMatrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz);
    ~RotationMatrix();

    G4RotationMatrix* AsG4RotaionMatrix();

    double xx;
    double xy;
    double xz;
    double yx;
    double yy;
    double yz;
    double zx;
    double zy;
    double zz;
};
