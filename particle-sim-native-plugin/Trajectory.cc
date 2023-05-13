#include "pch.h"

#include "util.hh"
#include "Trajectory.hh"

Trajectory::Trajectory(G4RichTrajectory* traj)
{
    this->trackID = traj->GetTrackID();
    this->parentID = traj->GetParentID();
    this->particleName = Util::GetCopiedStringPtr(traj->GetParticleName());
    this->charge = traj->GetCharge();
    this->pdgEncoding = traj->GetPDGEncoding();
    this->initialKinaticEnergy = traj->GetInitialKineticEnergy();
    this->initialMomentum = ThreeVector(traj->GetInitialMomentum());
    this->pointEntries = traj->GetPointEntries();
}

Trajectory::~Trajectory()
{
    delete particleName;
}
