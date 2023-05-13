#pragma once

#include <G4VUserPrimaryGeneratorAction.hh>

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction(G4ParticleGun* gun);
    ~PrimaryGeneratorAction() override;

    void GeneratePrimaries(G4Event*) override;

private:
    G4ParticleGun* fParticleGun;
};
