#pragma once

#include <G4RichTrajectory.hh>

#include "ThreeVector.hh"

struct Trajectory
{
public:
    Trajectory(G4RichTrajectory* traj);
    ~Trajectory();

    int trackID;
    int parentID;
    const char* particleName;
    double charge;
    int pdgEncoding;
    double initialKinaticEnergy;
    ThreeVector initialMomentum;
    int pointEntries;
};
