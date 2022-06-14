#ifndef COMMAND_H
#define COMMAND_H

#include "myrobot.h"


class Command
{

public:
    virtual void start(float god, float dod, MyRobot* robot) = 0;
    virtual bool update(float god, float dod, MyRobot* robot) = 0;
};

#endif // COMMAND_H
