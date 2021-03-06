/*----------------------------------------------------------------------------*/
/* Copyright (c) 2016-2017 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <functional>
#include <vector>

#include "SpeedController.h"

namespace frc {

class SpeedControllerGroup : public SpeedController {
 public:
  template <class... SpeedControllers>
  explicit SpeedControllerGroup(SpeedController& speedController,
                                SpeedControllers&... speedControllers);

  void Set(double speed) override;
  double Get() const override;
  void SetInverted(bool isInverted) override;
  bool GetInverted() const override;
  void Disable() override;
  void StopMotor() override;
  void PIDWrite(double output) override;

 private:
  bool m_isInverted = false;
  std::vector<std::reference_wrapper<SpeedController>> m_speedControllers;
};

}  // namespace frc

#include "SpeedControllerGroup.inc"
