#ifndef MOVE_H
#define MOVE_H

#include "command.h"

class Move : public Command
{
public:
    Move(float length); // in meters

    virtual void start(float god, float dod, MyRobot* robot);
    virtual bool update(float god, float dod, MyRobot* robot);

private:
    float length;
    float init_god;
    float init_dod;
};

#endif // MOVE_H
