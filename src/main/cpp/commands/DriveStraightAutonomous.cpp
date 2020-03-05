#include "commands/DriveStraightAutonomous.h"

#include "RobotContainer.h"

void DriveStraightAutonomous::End(bool interrupted){
}

void DriveStraightAutonomous::Initialize(){
}

void DriveStraightAutonomous::Execute(){

}

bool DriveStraightAutonomous::IsFinished(){
    return true;
}

DriveStraightAutonomous::DriveStraightAutonomous() {

    SetName( "DriveStraightDistance" );

    mStartTime = 0;
}