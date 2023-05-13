#pragma once

#include <G4UserTrackingAction.hh>

class TrackingAction : public G4UserTrackingAction
{
public:
    TrackingAction() : G4UserTrackingAction() {};
    virtual ~TrackingAction() {};

    virtual void PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);
};
