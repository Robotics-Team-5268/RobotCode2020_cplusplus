#pragma once

#include <memory>
#include <vector>

#include "RobotConfig.h"
#include "commands/Autonomous.h"
#include "subsystems/ColorWheel.h"
#include "subsystems/Drive.h"
#if( PNEUMATICS_SUPPORT )
    #include "subsystems/Pneumatics.h"
#endif

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

class RobotContainer
{
public:
    RobotContainer();

    frc2::Command* GetAutonomousCommand();
private:
    void ConfigureButtonBindings();

    std::shared_ptr<frc::Joystick> mDriverJoystick;
    std::vector<frc2::JoystickButton*> mDriverButtons;

    std::shared_ptr<frc::Joystick> mMechanismsJoystick;
    std::vector<frc2::JoystickButton*> mMechanismsButtons;

    ColorWheel mColorWheel;
    Drive mDrive;
    #if( PNEUMATICS_SUPPORT )
        Pneumatics mPneumatics;
    #endif

    Autonomous mAutonomousCommand;
};
