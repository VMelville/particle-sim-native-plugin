#include "pch.h"

#include <G4ParticleGun.hh>

#include "PrimaryGeneratorAction.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(G4ParticleGun* gun) :G4VUserPrimaryGeneratorAction()
{
	fParticleGun = gun;
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	fParticleGun->GeneratePrimaryVertex(anEvent);
}