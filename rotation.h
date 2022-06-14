#ifndef ROTATION_H
#define ROTATION_H

#include "command.h"


class Rotation : public Command
{
public:
    Rotation(int angle);

    virtual void start(float god, float dod, MyRobot* robot);
    virtual bool update(float god, float dod, MyRobot* robot);

private:
    int angle;
    float init_god;
    float init_dod;
};

#endif // ROTATION_H
