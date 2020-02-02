#pragma once

#include <frc/commands/Subsystem.h>
#include "rev/ColorSensorV3.h"

class ColorWheel : public frc::Subsystem {
    public:
        ColorWheel();

        virtual ~ColorWheel();

    private:
        rev::ColorSensorV3 mColorSensor;

};
