#include "pch.h"

#include <G4TrackingManager.hh>

#include "TrackingAction.hh"

void TrackingAction::PreUserTrackingAction(const G4Track* /*aTrack*/)
{
	fpTrackingManager->SetStoreTrajectory(3);
}

void TrackingAction::PostUserTrackingAction(const G4Track* /*aTrack*/)
{;}