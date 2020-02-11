#include "subsystems/ColorWheel.h"

// TODO: Set these colors based on our sensor
static constexpr frc::Color BlueTarget = frc::Color(0.143, 0.427, 0.429);
static constexpr frc::Color GreenTarget = frc::Color(0.197, 0.561, 0.240);
static constexpr frc::Color RedTarget = frc::Color(0.561, 0.232, 0.114);
static constexpr frc::Color YellowTarget = frc::Color(0.361, 0.524, 0.113);

ColorWheel::ColorWheel() 
    : Subsystem("ColorWheel")
    , mColorSensor( frc::I2C::Port::kOnboard )
{
    mColorMatcher.AddColorMatch(BlueTarget);
    mColorMatcher.AddColorMatch(GreenTarget);
    mColorMatcher.AddColorMatch(RedTarget);
    mColorMatcher.AddColorMatch(YellowTarget);
}

ColorWheel::~ColorWheel()
{

}

ColorWheel::ColorReading ColorWheel::readColorSensor()
{
    ColorReading reading;
    reading.color = mColorSensor.GetColor();
    frc::Color closestColor = mColorMatcher.MatchClosestColor( reading.color, reading.matchConfidence );

    if( BlueTarget == closestColor )
    {
        reading.matchedColor = BLUE;
    }
    else if( GreenTarget == closestColor )
    {
        reading.matchedColor = GREEN;
    }
    else if( RedTarget == closestColor )
    {
        reading.matchedColor = RED;
    }
    else if( YellowTarget == closestColor )
    {
        reading.matchedColor = YELLOW;
    }    

    return reading;

}

void ColorWheel::spin( double aPercentSpeed )
{
    mSpeedController.Set( aPercentSpeed );
}
