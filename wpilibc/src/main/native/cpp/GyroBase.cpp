/*----------------------------------------------------------------------------*/
/* Copyright (c) 2008-2017 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GyroBase.h"

#include "LiveWindow/LiveWindow.h"
#include "WPIErrors.h"

using namespace frc;

/**
 * Get the PIDOutput for the PIDSource base object. Can be set to return
 * angle or rate using SetPIDSourceType(). Defaults to angle.
 *
 * @return The PIDOutput (angle or rate, defaults to angle)
 */
double GyroBase::PIDGet() {
  switch (GetPIDSourceType()) {
    case PIDSourceType::kRate:
      return GetRate();
    case PIDSourceType::kDisplacement:
      return GetAngle();
    default:
      return 0;
  }
}

void GyroBase::UpdateTable() {
  if (m_valueEntry) m_valueEntry.SetDouble(GetAngle());
}

void GyroBase::StartLiveWindowMode() {}

void GyroBase::StopLiveWindowMode() {}

std::string GyroBase::GetSmartDashboardType() const { return "Gyro"; }

void GyroBase::InitTable(std::shared_ptr<nt::NetworkTable> subTable) {
  if (subTable) {
    m_valueEntry = subTable->GetEntry("Value");
    UpdateTable();
  } else {
    m_valueEntry = nt::NetworkTableEntry();
  }
}
