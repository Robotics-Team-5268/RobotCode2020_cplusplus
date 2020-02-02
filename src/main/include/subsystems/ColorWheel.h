#pragma once

#include <ctre/Phoenix.h>
#include <frc/commands/Subsystem.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "RobotMap.h"

class ColorWheel : public frc::Subsystem {
    public:
        enum MatchedColor
        {
            BLUE,
            GREEN,
            RED,
            YELLOW,
            NO_MATCH
        };

        ColorWheel();

        virtual ~ColorWheel();

        frc::Color getColor();

        MatchedColor getMatchedColor();

    private:
        rev::ColorSensorV3 mColorSensor;
        rev::ColorMatch mColorMatcher;
        WPI_TalonSRX speedController{COLOR_WHEEL_SPEED_CONTROLLER};

};
