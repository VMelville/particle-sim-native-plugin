#include "pch.h"

#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4UniformMagField.hh>
#include <G4FieldManager.hh>
#include <G4SystemOfUnits.hh>

#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction(G4NistManager* nist) : G4VUserDetectorConstruction(), worldVolume()
{
	auto* solid = new G4Box("DefaultWorld", 1 * m, 1 * m, 1 * m);
	auto* material = nist->FindOrBuildMaterial("G4_AIR", true);
	auto* logicalVolume = new G4LogicalVolume(solid, material, "DefaultWorld");
	worldVolume = new G4PVPlacement(new G4RotationMatrix(), G4ThreeVector(), "DefaultWorld", logicalVolume, 0, false, 0, true);
}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	return worldVolume;
}

void DetectorConstruction::SetWorldVolume(G4PVPlacement* worldVolume)
{
	delete this->worldVolume;
	this->worldVolume = worldVolume;
}
