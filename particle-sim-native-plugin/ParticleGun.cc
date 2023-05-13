#include "pch.h"

#include "ParticleGun.hh"
#include "ThreeVector.hh"

#include <G4ParticleTable.hh>

ParticleGun::ParticleGun(int numberOfParticles, const char* particleName, ThreeVector position, ThreeVector direction, double energy)
{
	this->numberOfParticles = numberOfParticles;
	this->particleName = particleName;
	this->position = position;
	this->direction = direction;
	this->energy = energy;
}

ParticleGun::~ParticleGun()
{
}

void ParticleGun::UpdateParticleGunParameter(G4ParticleGun* particleGun)
{
	particleGun->SetNumberOfParticles(numberOfParticles);
	particleGun->SetParticleDefinition(G4ParticleTable::GetParticleTable()->FindParticle(particleName));
	particleGun->SetParticlePosition(position.AsG4ThreeVector());
	particleGun->SetParticleMomentumDirection(direction.AsG4ThreeVector());
	particleGun->SetParticleEnergy(energy);
}
