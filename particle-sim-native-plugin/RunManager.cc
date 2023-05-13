#include "pch.h"

#include "RunManager.hh"

RunManager::RunManager() : G4RunManager()
{}

RunManager::~RunManager()
{}

void RunManager::TerminateOneEvent()
{
    delete lastTrajectoryContainer;
    lastTrajectoryContainer = currentEvent->GetTrajectoryContainer();

    G4RunManager::TerminateOneEvent();
}
