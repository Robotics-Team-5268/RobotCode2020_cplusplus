#pragma once

#include <ctre/Phoenix.h>
#include <frc2/command/SubsystemBase.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "RobotMap.h"

class ColorWheel : public frc2::SubsystemBase {
    public:
        enum MatchedColor
        {
            BLUE,
            GREEN,
            RED,
            YELLOW,
            NO_MATCH
        };

        struct ColorReading
        {
            ColorReading()
                : matchedColor( NO_MATCH )
                , matchConfidence( 0.0 )
            {

            }

            frc::Color color;
            MatchedColor matchedColor;
            double matchConfidence;
        };

        ColorWheel();

        virtual ~ColorWheel();

        ColorReading readColorSensor();

        frc::Color getColor();

        MatchedColor getMatchedColor();

        void spin( double aPercentSpeed );

    private:
        rev::ColorSensorV3 mColorSensor;
        rev::ColorMatch mColorMatcher;
        WPI_TalonSRX mSpeedController{COLOR_WHEEL_SPEED_CONTROLLER};

};
