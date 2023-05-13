#pragma once

#include <G4RunManager.hh>

class RunManager : public G4RunManager
{
public:
    RunManager();
    ~RunManager() override;
    void TerminateOneEvent();
    G4TrajectoryContainer* GetLastTrajectoryContainer() { return lastTrajectoryContainer; }

private:
    G4TrajectoryContainer* lastTrajectoryContainer = nullptr;
};
