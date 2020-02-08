#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class Winches : public frc::Subsystem {
public:
    Winches();
    virtual ~Winches();

    void lift( double aPercent );

    void telescope( double aPercent );

private:
    WPI_VictorSPX telescopeSpeedController{WINCH_TELESCOPE_SPEED_CONTROLLER};

    WPI_VictorSPX pullupSpeedController1{WINCH_PULLUP_SPEED_CONTROLLER};

};
