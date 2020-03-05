#include "commands/Autonomous.h"

Autonomous::Autonomous( Drive* aDrive, int aSelection )
  : mDrive( aDrive )
{
  SetName( "Autonomous" );

  AddRequirements( mDrive );

}

void Autonomous::End(bool interrupted)
{
  mDrive->setMotors(0.0, 0.0);
}

void Autonomous::Initialize()
{

}

void Autonomous::Execute()
{

}

bool Autonomous::IsFinished()
{
  return true;
}