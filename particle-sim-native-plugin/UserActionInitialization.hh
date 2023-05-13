#pragma once

#include <G4VUserActionInitialization.hh>

class UserActionInitialization : public G4VUserActionInitialization
{
public:
    UserActionInitialization();
    virtual ~UserActionInitialization() override;

    virtual void Build() const override;
};
