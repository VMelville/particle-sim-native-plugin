#pragma once

#include "G4VModularPhysicsList.hh"

class ParticleSimPhysicsList : public G4VModularPhysicsList
{
public:
	ParticleSimPhysicsList(G4int ver = 1);
	virtual ~ParticleSimPhysicsList();

	virtual void SetCuts();
};
