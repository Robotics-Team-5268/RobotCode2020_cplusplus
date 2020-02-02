#include "subsystems/ColorWheel.h"

// TODO: Set these colors based on our sensor
static constexpr frc::Color sBlueTarget = frc::Color(0.143, 0.427, 0.429);
static constexpr frc::Color sGreenTarget = frc::Color(0.197, 0.561, 0.240);
static constexpr frc::Color sRedTarget = frc::Color(0.561, 0.232, 0.114);
static constexpr frc::Color sYellowTarget = frc::Color(0.361, 0.524, 0.113);

ColorWheel::ColorWheel() 
    : Subsystem("ColorWheel")
    , mColorSensor( frc::I2C::Port::kOnboard )
{
    mColorMatcher.AddColorMatch(sBlueTarget);
    mColorMatcher.AddColorMatch(sGreenTarget);
    mColorMatcher.AddColorMatch(sRedTarget);
    mColorMatcher.AddColorMatch(sYellowTarget);
}

ColorWheel::~ColorWheel()
{

}

frc::Color ColorWheel::getColor()
{
    return mColorSensor.GetColor();
}

ColorWheel::MatchedColor ColorWheel::getMatchedColor()
{
    double confidence = 0.0;
    frc::Color detectedColor = getColor();
    frc::Color matchedColor = mColorMatcher.MatchClosestColor( detectedColor, confidence );

    MatchedColor matchValue = NO_MATCH;
    if( sBlueTarget == matchedColor )
    {
        matchValue = BLUE;
    }
    else if( sGreenTarget == matchedColor )
    {
        matchValue = GREEN;
    }
    else if( sRedTarget == matchedColor )
    {
        matchValue = RED;
    }
    else if( sYellowTarget == matchedColor )
    {
        matchValue = YELLOW;
    }

    return matchValue;
}
