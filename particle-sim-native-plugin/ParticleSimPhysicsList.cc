#include "pch.h"

#include "ParticleSimPhysicsList.hh"

#include <G4EmStandardPhysics_option1.hh>
#include <G4EmExtraPhysics.hh>
#include <G4DecayPhysics.hh>
#include <G4IonPhysics.hh>
#include <G4StoppingPhysics.hh>
#include <G4HadronElasticPhysics.hh>
#include <G4NeutronTrackingCut.hh>
#include <G4OpticalPhysics.hh>
#include <G4ProcessManager.hh>
#include <G4ParticleTypes.hh>
#include <G4SystemOfUnits.hh>
#include <G4HadronPhysicsFTFP_BERT.hh>

ParticleSimPhysicsList::ParticleSimPhysicsList(G4int ver)
{
	defaultCutValue = 0.7 * CLHEP::mm;
	SetVerboseLevel(ver);

	// EM Physics
	RegisterPhysics(new G4EmStandardPhysics_option1(ver));

	// Synchroton Radiation & GN Physics
	RegisterPhysics(new G4EmExtraPhysics(ver));

	// Decays
	RegisterPhysics(new G4DecayPhysics(ver));

	// Hadron Elastic scattering
	RegisterPhysics(new G4HadronElasticPhysics(ver));

	// Hadron Inelastic physics
	RegisterPhysics(new G4HadronPhysicsFTFP_BERT(ver));

	// Stopping Physics
	RegisterPhysics(new G4StoppingPhysics(ver));

	// Ion Physics
	RegisterPhysics(new G4IonPhysics(ver));

	// Neutron tracking cut
	auto* neutronTrackingCut = new G4NeutronTrackingCut(ver);
	neutronTrackingCut->SetKineticEnergyLimit(40 * MeV);
	RegisterPhysics(neutronTrackingCut);
}

ParticleSimPhysicsList::~ParticleSimPhysicsList()
{
}

void ParticleSimPhysicsList::SetCuts()
{
	this->SetCutsWithDefault();
}
