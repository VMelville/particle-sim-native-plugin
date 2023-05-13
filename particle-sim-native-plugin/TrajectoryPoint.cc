#include "pch.h"

#include <G4AttValue.hh>

#include "TrajectoryPoint.hh"
#include "util.hh"

TrajectoryPoint::TrajectoryPoint(G4RichTrajectoryPoint* trajectoryPoint)
{
    auto* att = trajectoryPoint->CreateAttValues();

    this->position = trajectoryPoint->GetPosition();
    this->totalEnergyDeposit = Util::To_MeV(att->at(1).GetValue());
    this->remainingEnergy = Util::To_MeV(att->at(2).GetValue());
    this->processDefinedStep = Util::GetCopiedStringPtr(att->at(3).GetValue());
    this->processTypeDefinedStep = Util::GetCopiedStringPtr(att->at(4).GetValue());
    this->preStepPointStatus = Util::GetCopiedStringPtr(att->at(5).GetValue());
    this->postStepPointStatus = Util::GetCopiedStringPtr(att->at(6).GetValue());
    this->preStepPointGlobalTime = Util::To_NS(att->at(7).GetValue());
    this->postStepPointGlobalTime = Util::To_NS(att->at(8).GetValue());
    this->preStepPointGlobalTimeStr = Util::GetCopiedStringPtr(att->at(7).GetValue());
    this->postStepPointGlobalTimeStr = Util::GetCopiedStringPtr(att->at(8).GetValue());
    this->preStepVolumePath = Util::GetCopiedStringPtr(att->at(9).GetValue());
    this->postStepVolumePath = Util::GetCopiedStringPtr(att->at(10).GetValue());
    this->preStepPointWeight = std::stod(att->at(11).GetValue());
    this->postStepPointWeight = std::stod(att->at(12).GetValue());

    if (trajectoryPoint->GetAuxiliaryPoints())
    {
        this->auxiliaryPointsSize = trajectoryPoint->GetAuxiliaryPoints()->size();
    }
    else
    {
        this->auxiliaryPointsSize = 0;
    }
}

TrajectoryPoint::~TrajectoryPoint()
{
}
