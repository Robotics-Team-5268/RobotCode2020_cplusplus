#pragma once

#include <memory>

#include <string.h>

#include "RobotConfig.h"
#include "subsystems/ColorWheel.h"
#include "subsystems/Drive.h"
#if( PNEUMATICS_SUPPORT )
    #include "subsystems/Pneumatics.h"
#endif
#include "OI.h"

class Commands
{
 public:
  static void init();

  static std::unique_ptr<ColorWheel> colorWheel;
  static std::unique_ptr<Drive> drive;
  #if( PNEUMATICS_SUPPORT )
      static std::unique_ptr<Pneumatics> pneumatics;
  #endif
  static std::unique_ptr<OI> oi;
};
