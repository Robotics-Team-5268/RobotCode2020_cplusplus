#pragma once

#include "CommandBase.h"

class DriveStraightAutonomous : public CommandBase {
private:
    double mStartTime;
public:
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    DriveStraightAutonomous();
};
