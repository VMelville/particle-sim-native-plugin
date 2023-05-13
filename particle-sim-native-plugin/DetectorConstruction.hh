#pragma once

#include <G4VUserDetectorConstruction.hh>
#include <G4PVPlacement.hh>
#include <G4NistManager.hh>

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction(G4NistManager* nist);
    virtual ~DetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
    void SetWorldVolume(G4PVPlacement* worldVolume);

private:
    G4VPhysicalVolume* worldVolume;
};
