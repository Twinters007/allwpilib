/*----------------------------------------------------------------------------*/
/* Copyright (c) 2014-2017 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>
#include <string>

#include "LiveWindow/LiveWindowSendable.h"
#include "SensorBase.h"
#include "networktables/NetworkTableEntry.h"

namespace frc {

/**
 * Class for getting voltage, current, temperature, power and energy from the
 * CAN PDP.
 */
class PowerDistributionPanel : public SensorBase, public LiveWindowSendable {
 public:
  PowerDistributionPanel();
  explicit PowerDistributionPanel(int module);

  double GetVoltage() const;
  double GetTemperature() const;
  double GetCurrent(int channel) const;
  double GetTotalCurrent() const;
  double GetTotalPower() const;
  double GetTotalEnergy() const;
  void ResetTotalEnergy();
  void ClearStickyFaults();

  void UpdateTable() override;
  void StartLiveWindowMode() override;
  void StopLiveWindowMode() override;
  std::string GetSmartDashboardType() const override;
  void InitTable(std::shared_ptr<nt::NetworkTable> subTable) override;

 private:
  nt::NetworkTableEntry m_chanEntry[16];
  nt::NetworkTableEntry m_voltageEntry;
  nt::NetworkTableEntry m_totalCurrentEntry;
  int m_module;
};

}  // namespace frc
