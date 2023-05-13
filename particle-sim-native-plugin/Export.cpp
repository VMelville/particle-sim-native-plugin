#include "pch.h"

#include <QGSP_BERT.hh>
#include <FTFP_BERT.hh>

#include <G4SystemOfUnits.hh>
#include <G4UniformMagField.hh>
#include <G4Box.hh>
#include <G4Cons.hh>
#include <G4Orb.hh>
#include <G4Para.hh>
#include <G4Sphere.hh>
#include <G4Torus.hh>
#include <G4Trap.hh>
#include <G4Trd.hh>
#include <G4Tubs.hh>
#include <G4PVReplica.hh>

#include "Export.h"

#include "Util.hh"
#include "UserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "ParticleSimPhysicsList.hh"

EXPORT void Init()
{
    if (mRunManager == NULL)
    {
        mNist = G4NistManager::Instance();

        mRunManager = new RunManager();
        mRunManager->SetNumberOfEventsToBeStored(1);

        mDetectorConstruction = new DetectorConstruction(mNist);
        mRunManager->SetUserInitialization(mDetectorConstruction);

        mRunManager->SetUserInitialization(new ParticleSimPhysicsList);

        mParticleGun = new G4ParticleGun(1);

        mRunManager->SetUserInitialization(new UserActionInitialization);
        mRunManager->SetUserAction(new PrimaryGeneratorAction(mParticleGun));
        mRunManager->Initialize();
    }
}

EXPORT void BeamOn()
{
    if (mRunManager == NULL) return;

    mRunManager->BeamOn(1);
    return;
}

EXPORT void SetParticleGun(ParticleGun particleGun)
{
    if (mParticleGun == NULL) return;

    particleGun.UpdateParticleGunParameter(mParticleGun);
}

G4Box* CreateBox(const char* name, double x, double y, double z)
{
    return new G4Box(name, x, y, z);
}

G4Cons* CreateCons(const char* name, double rMin1, double rMax1, double rMin2, double rMax2, double dz, double sPhi, double dPhi)
{
    return new G4Cons(name, rMin1, rMax1, rMin2, rMax2, dz, sPhi, dPhi);
}

G4Orb* CreateOrb(const char* name, double rMax)
{
    return new G4Orb(name, rMax);
}

G4Para* CreatePara(const char* name, double dx, double dy, double dz, double alpha, double theta, double phi)
{
    return new G4Para(name, dx, dy, dz, alpha, theta, phi);
}

G4Sphere* CreateSphere(const char* name, double rMin, double rMax, double sPhi, double dPhi, double sTheta, double dTheta)
{
    return new G4Sphere(name, rMin, rMax, sPhi, dPhi, sTheta, dTheta);
}

G4Torus* CreateTorus(const char* name, double rMin, double rMax, double rTor, double sPhi, double dPhi)
{
    return new G4Torus(name, rMin, rMax, rTor, sPhi, dPhi);
}

G4Trap* CreateTrap(const char* name, double dz, double theta, double phi, double dy1, double dx1, double dx2, double alp1, double dy2, double dx3, double dx4, double alp2)
{
    return new G4Trap(name, dz, theta, phi, dy1, dx1, dx2, alp1, dy2, dx3, dx4, alp2);
}

G4Trd* CreateTrd(const char* name, double dx1, double dx2, double dy1, double dy2, double dz)
{
    return new G4Trd(name, dx1, dx2, dy1, dy2, dz);
}

G4Tubs* CreateTubs(const char* name, double rMin, double rMax, double dz, double sPhi, double dPhi)
{
    return new G4Tubs(name, rMin, rMax, dz, sPhi, dPhi);
}

G4Material* FindOrBuildMaterial(const char* materialName)
{
    return mNist->FindOrBuildMaterial(materialName, true);
}

G4FieldManager* CreateFieldManagerWithMagField(ThreeVector magField)
{
    return new G4FieldManager{ new G4UniformMagField(magField.AsG4ThreeVector()) };
}

G4LogicalVolume* CreateLogicalVolume(G4CSGSolid* solid, G4Material* material, const char* name)
{
    return new G4LogicalVolume(solid, material, name);
}

G4LogicalVolume* CreateLogicalVolumeWithField(G4CSGSolid* solid, G4Material* material, const char* name, G4FieldManager* fieldManager)
{
    return new G4LogicalVolume(solid, material, name, fieldManager);
}

G4PVPlacement* CreatePVPlacement(RotationMatrix rotation, ThreeVector position, const char* name, G4LogicalVolume* logicalVolume, G4VPhysicalVolume* mother, bool many, int copyNo, bool surfChk)
{
    return new G4PVPlacement(rotation.AsG4RotaionMatrix(), position.AsG4ThreeVector(), name, logicalVolume, mother, many, copyNo, surfChk);
}

void SetWorldVolume(G4PVPlacement* worldolume)
{
    mDetectorConstruction->SetWorldVolume(worldolume);
}

void InitializeGeometry()
{
    mRunManager->InitializeGeometry();
}

void ReinitializeGeometry()
{
    mRunManager->ReinitializeGeometry();
}

G4PVReplica* CreatePVReplica(const char* name, G4LogicalVolume* logical, G4LogicalVolume* mother, int axis, int nReplicas, double width, double offset)
{
    return new G4PVReplica(name, logical, mother, (EAxis)axis, nReplicas, width, offset);
}

// Trajectory

Trajectory* GetTrajectory(int trajectoryIndex)
{
    auto* traj = (G4RichTrajectory*)((*(mRunManager->GetLastTrajectoryContainer()))[trajectoryIndex]);
    return new Trajectory(traj);
}

int GetTrajectoryContainerEntries()
{
    return mRunManager->GetLastTrajectoryContainer()->entries();
}

TrajectoryPoint* GetTrajectoryPoint(int trajectoryIndex, int pointIndex)
{
    auto* traj = (G4RichTrajectory*)((*(mRunManager->GetLastTrajectoryContainer()))[trajectoryIndex]);
    auto* point = (G4RichTrajectoryPoint*)traj->GetPoint(pointIndex);
    return new TrajectoryPoint(point);
}

ThreeVector GetAuxiliaryPoint(int trajectoryIndex, int pointIndex, int auxiliaryPointIndex)
{
    auto* traj = (G4RichTrajectory*)((*(mRunManager->GetLastTrajectoryContainer()))[trajectoryIndex]);
    auto* point = (G4RichTrajectoryPoint*)traj->GetPoint(pointIndex);
    return ThreeVector(point->GetAuxiliaryPoints()->at(auxiliaryPointIndex));
}

// Particle

EXPORT const char* GetParticleName(const char* particleName)
{
    return Util::GetCopiedStringPtr(G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetParticleName());
}

EXPORT double GetPDGMass(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGMass();
}

EXPORT double GetPDGWidth(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGWidth();
}

EXPORT double GetPDGCharge(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGCharge();
}

EXPORT double GetPDGSpin(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGSpin();
}

EXPORT int GetPDGiSpin(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiSpin();
}

EXPORT int GetPDGiParity(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiParity();
}

EXPORT int GetPDGiConjugation(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiConjugation();
}

EXPORT double GetPDGIsospin(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGIsospin();
}

EXPORT double GetPDGIsospin3(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGIsospin3();
}

EXPORT int GetPDGiIsospin(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiIsospin();
}

EXPORT int GetPDGiIsospin3(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiIsospin3();
}

EXPORT int GetPDGiGParity(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGiGParity();
}

EXPORT double GetPDGMagneticMoment(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGMagneticMoment();
}

EXPORT const char* GetParticleType(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetParticleType();
}

EXPORT const char* GetParticleSubType(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetParticleSubType();
}

EXPORT int GetLeptonNumber(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetLeptonNumber();
}

EXPORT int GetBaryonNumber(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetBaryonNumber();
}

EXPORT int GetPDGEncoding(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGEncoding();
}

EXPORT int GetAntiPDGEncoding(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetAntiPDGEncoding();
}

EXPORT int GetQuarkContent(const char* particleName, int flavor)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetQuarkContent(flavor);
}

EXPORT int GetAntiQuarkContent(const char* particleName, int flavor)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetAntiQuarkContent(flavor);
}

EXPORT bool GetPDGStable(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGStable();
}

EXPORT double GetPDGLifeTime(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetPDGLifeTime();
}

EXPORT int GetAtomicNumber(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetAtomicNumber();
}

EXPORT int GetAtomicMass(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetAtomicMass();
}

EXPORT int GetVerboseLevel(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetVerboseLevel();
}

EXPORT bool GetApplyCutsFlag(const char* particleName)
{
    return G4ParticleTable::GetParticleTable()->FindParticle(particleName)->GetApplyCutsFlag();
}
