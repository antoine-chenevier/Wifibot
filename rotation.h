#ifndef ROTATION_H
#define ROTATION_H

#include "command.h"


class Rotation : Command
{
public:
    Rotation(int angle);


private:
    int angle;
};

#endif // ROTATION_H
