#include "pch.h"

#include "RotationMatrix.hh"

RotationMatrix::RotationMatrix()
{
	xx = 0.0;
	xy = 0.0;
	xz = 0.0;
	yx = 0.0;
	yy = 0.0;
	yz = 0.0;
	zx = 0.0;
	zy = 0.0;
	zz = 0.0;
}

RotationMatrix::RotationMatrix(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz)
{
	this->xx = xx;
	this->xy = xy;
	this->xz = xz;
	this->yx = yx;
	this->yy = yy;
	this->yz = yz;
	this->zx = zx;
	this->zy = zy;
	this->zz = zz;
}

RotationMatrix::~RotationMatrix()
{
}

G4RotationMatrix* RotationMatrix::AsG4RotaionMatrix()
{
	CLHEP::HepRep3x3 hr = CLHEP::HepRep3x3(xx, xy, xz, yx, yy, yz, zx, zy, zz);
	return new G4RotationMatrix(hr);
}
