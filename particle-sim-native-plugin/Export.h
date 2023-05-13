#pragma once

#include <G4ParticleGun.hh>
#include <G4NistManager.hh>
#include <G4CSGSolid.hh>
#include <G4FieldManager.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4PVReplica.hh>

#include "RunManager.hh"
#include "DetectorConstruction.hh"
#include "Trajectory.hh"
#include "TrajectoryPoint.hh"
#include "ParticleGun.hh"
#include "RotationMatrix.hh"

#ifdef PARTICLESIMNATIVEPLUGIN_EXPORTS
#   define EXPORT __declspec(dllexport)
#else
#   define EXPORT __declspec(dllimport)
#endif

RunManager* mRunManager;
G4ParticleDefinition* mParticle;
G4ParticleGun* mParticleGun;
DetectorConstruction* mDetectorConstruction;
G4NistManager* mNist;

std::vector<G4LogicalVolume*> test;

extern "C"
{
    EXPORT void Init();
    EXPORT void BeamOn();

    EXPORT void SetParticleGun(ParticleGun particleGun);

    EXPORT G4Box* CreateBox(const char* name, double x, double y, double z);
    EXPORT G4Cons* CreateCons(const char* name, double rMin1, double rMax1, double rMin2, double rMax2, double dz, double sPhi, double dPhi);
    EXPORT G4Orb* CreateOrb(const char* name, double rMax);
    EXPORT G4Para* CreatePara(const char* name, double dx, double dy, double dz, double alpha, double theta, double phi);
    EXPORT G4Sphere* CreateSphere(const char* name, double rMin, double rMax, double sPhi, double dPhi, double sTheta, double dTheta);
    EXPORT G4Torus* CreateTorus(const char* name, double rMin, double rMax, double rTor, double sPhi, double dPhi);
    EXPORT G4Trap* CreateTrap(const char* name, double dz, double theta, double phi, double dy1, double dx1, double dx2, double alp1, double dy2, double dx3, double dx4, double alp2);
    EXPORT G4Trd* CreateTrd(const char* name, double dx1, double dx2, double dy1, double dy2, double dz);
    EXPORT G4Tubs* CreateTubs(const char* name, double rMin, double rMax, double dz, double sPhi, double dPhi);

    EXPORT G4Material* FindOrBuildMaterial(const char* materialName);
    EXPORT G4FieldManager* CreateFieldManagerWithMagField(ThreeVector magField);
    EXPORT G4LogicalVolume* CreateLogicalVolume(G4CSGSolid* solid, G4Material* material, const char* name);
    EXPORT G4LogicalVolume* CreateLogicalVolumeWithField(G4CSGSolid* solid, G4Material* material, const char* name, G4FieldManager* fieldManager);

    EXPORT G4PVPlacement* CreatePVPlacement(RotationMatrix rotation, ThreeVector position, const char* name, G4LogicalVolume* logicalVolume, G4VPhysicalVolume* mother, bool many, int copyNum, bool surfChk);
    EXPORT void SetWorldVolume(G4PVPlacement* worldolume);
    EXPORT void InitializeGeometry();
    EXPORT void ReinitializeGeometry();

    EXPORT G4PVReplica* CreatePVReplica(const char* name, G4LogicalVolume* logical, G4LogicalVolume* mother, int axis, int nReplicas, double width, double offset);

    EXPORT int GetTrajectoryContainerEntries();
    EXPORT Trajectory* GetTrajectory(int trajectoryIndex);
    EXPORT TrajectoryPoint* GetTrajectoryPoint(int trajectoryIndex, int pointIndex);
    EXPORT ThreeVector GetAuxiliaryPoint(int trajectoryIndex, int pointIndex, int auxiliaryPointIndex);

    EXPORT const char* GetParticleName(const char* particleName);
    EXPORT double GetPDGMass(const char* particleName);
    EXPORT double GetPDGWidth(const char* particleName);
    EXPORT double GetPDGCharge(const char* particleName);
    EXPORT double GetPDGSpin(const char* particleName);
    EXPORT int GetPDGiSpin(const char* particleName);
    EXPORT int GetPDGiParity(const char* particleName);
    EXPORT int GetPDGiConjugation(const char* particleName);
    EXPORT double GetPDGIsospin(const char* particleName);
    EXPORT double GetPDGIsospin3(const char* particleName);
    EXPORT int GetPDGiIsospin(const char* particleName);
    EXPORT int GetPDGiIsospin3(const char* particleName);
    EXPORT int GetPDGiGParity(const char* particleName);
    EXPORT double GetPDGMagneticMoment(const char* particleName);
    EXPORT const char* GetParticleType(const char* particleName);
    EXPORT const char* GetParticleSubType(const char* particleName);
    EXPORT int GetLeptonNumber(const char* particleName);
    EXPORT int GetBaryonNumber(const char* particleName);
    EXPORT int GetPDGEncoding(const char* particleName);
    EXPORT int GetAntiPDGEncoding(const char* particleName);
    EXPORT int GetQuarkContent(const char* particleName, int flavor);
    EXPORT int GetAntiQuarkContent(const char* particleName, int flavor);
    EXPORT bool GetPDGStable(const char* particleName);
    EXPORT double GetPDGLifeTime(const char* particleName);
    // EXPORT G4DecayTable * GetDecayTable (const char* particleName);
    // EXPORT G4ProcessManager * GetProcessManager (const char* particleName);
    // EXPORT G4ParticleTable * GetParticleTable (const char* particleName);
    EXPORT int GetAtomicNumber(const char* particleName);
    EXPORT int GetAtomicMass(const char* particleName);
    EXPORT int GetVerboseLevel(const char* particleName);
    EXPORT bool GetApplyCutsFlag(const char* particleName);
}
