#include <commands/SpinColor.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/ColorWheel.h>

SpinColor::SpinColor()
    : CommandBase("SpinColor")
    , mDesiredColor( ColorWheel::BLUE )
{
    Requires( colorWheel.get() );

        // RWH TODO: Set desired color based on field management system

}

void SpinColor::Initialize() {}

void SpinColor::Execute() {
    ColorWheel::ColorReading colorReading = colorWheel->readColorSensor();

    std::string colorString = "No Match";
    switch( colorReading.matchedColor )
    {
    case ColorWheel::BLUE:
        colorString = "Blue";
        break;

    case ColorWheel::YELLOW:
        colorString = "Yellow";
        break;

    case ColorWheel::GREEN:
        colorString = "Green";
        break;
    
    case ColorWheel::RED:
        colorString = "Red";
        break;

    default:
        break;
    }

    frc::SmartDashboard::PutNumber("Red", colorReading.color.red);
    frc::SmartDashboard::PutNumber("Green", colorReading.color.green);
    frc::SmartDashboard::PutNumber("Blue", colorReading.color.blue);
    frc::SmartDashboard::PutNumber("Confidence", colorReading.matchConfidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
}

bool SpinColor::IsFinished() { 
    return true; 
}

void SpinColor::End()
{

}

void SpinColor::Interrupted()
{

}
