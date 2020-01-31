#include "commands/DriveStraightAutonomous.h"


void DriveStraightAutonomous::End(){
}

void DriveStraightAutonomous::Initialize(){
}

void DriveStraightAutonomous::Execute(){

}

bool DriveStraightAutonomous::IsFinished(){
    return true;
}

DriveStraightAutonomous::DriveStraightAutonomous() : CommandBase("DriveStraightDistance") {
    mStartTime = 0;
}