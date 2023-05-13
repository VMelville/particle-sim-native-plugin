#pragma once

#include <G4RichTrajectoryPoint.hh>

#include "ThreeVector.hh"

struct TrajectoryPoint
{
public:
    TrajectoryPoint(G4RichTrajectoryPoint* trajctoryPoint);
    ~TrajectoryPoint();

    ThreeVector position;
    double totalEnergyDeposit;
    double remainingEnergy;
    const char* processDefinedStep;
    const char* processTypeDefinedStep;
    const char* preStepPointStatus;
    const char* postStepPointStatus;
    double preStepPointGlobalTime;
    double postStepPointGlobalTime;
    const char* preStepPointGlobalTimeStr;
    const char* postStepPointGlobalTimeStr;
    const char* preStepVolumePath;
    const char* postStepVolumePath;
    double preStepPointWeight;
    double postStepPointWeight;
    int auxiliaryPointsSize;
};
