#include "pch.h"

#include "UserActionInitialization.hh"

#include "TrackingAction.hh"

UserActionInitialization::UserActionInitialization() : G4VUserActionInitialization{}
{}

UserActionInitialization::~UserActionInitialization()
{}

void UserActionInitialization::Build() const
{
	SetUserAction(new TrackingAction);
}
