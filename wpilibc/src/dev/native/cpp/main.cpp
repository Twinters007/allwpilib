/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

#include <HAL/HAL.h>

#include "WPILibVersion.h"

int main() {
  std::cout << "Hello World" << std::endl;
  std::cout << HAL_GetRuntimeType() << std::endl;
  std::cout << GetWPILibVersion() << std::endl;
  return 0;
}
