#pragma once

#include <frc/commands/Command.h>

class DriveStraightAutonomous : public frc::Command {
public:
    DriveStraightAutonomous();

    virtual ~DriveStraightAutonomous() {};
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
};
