#pragma once

#include "CommandBase.h"

class DriveStraightAutonomous : public CommandBase {
public:
    DriveStraightAutonomous();

    virtual ~DriveStraightAutonomous() {};
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
};
