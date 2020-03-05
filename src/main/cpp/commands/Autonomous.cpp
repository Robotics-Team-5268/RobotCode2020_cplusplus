#include "commands/Autonomous.h"

Autonomous::Autonomous( Drive* aDrive, int aSelection )
  : mDrive( aDrive )
{
  SetName( "Autonomous" );

  Requires( mDrive );

}

void Autonomous::End()
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