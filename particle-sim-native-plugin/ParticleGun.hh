#pragma once

#include <G4ParticleGun.hh>

#include "ThreeVector.hh"

struct ParticleGun
{
public:
    ParticleGun(int numberOfParticles, const char* particleName, ThreeVector position, ThreeVector direction, double energy);
    ~ParticleGun();

    void UpdateParticleGunParameter(G4ParticleGun* particleGun);

    int numberOfParticles;
    const char* particleName;
    ThreeVector position;
    ThreeVector direction;
    double energy;
};
