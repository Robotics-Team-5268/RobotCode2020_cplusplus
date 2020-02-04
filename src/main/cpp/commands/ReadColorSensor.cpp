#include <commands/ReadColorSensor.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <subsystems/ColorWheel.h>


ReadColorSensor::ReadColorSensor() : CommandBase("ReadColorSensor") {
    Requires( colorWheel.get() );
}

void ReadColorSensor::Initialize() {}

void ReadColorSensor::Execute() {
    frc::Color detectedColor = colorWheel->getColor();
    ColorWheel::MatchedColor matchedColor = colorWheel->getMatchedColor();

    std::string colorString = "No Match";
    switch( matchedColor )
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
    }

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutString("Detected Color", colorString);    
}

bool ReadColorSensor::IsFinished() { 
    return true; 
}

void ReadColorSensor::End()
{

}

void ReadColorSensor::Interrupted()
{

}
