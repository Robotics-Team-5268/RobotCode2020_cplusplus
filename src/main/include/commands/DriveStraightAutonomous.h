#pragma once

#include "RobotContainer.h"

class DriveStraightAutonomous : public RobotContainer {
public:
    DriveStraightAutonomous();

    virtual ~DriveStraightAutonomous() {};
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
};
