#ifndef MOVE_H
#define MOVE_H

#include "command.h"

class Move : Command
{
public:
    Move(int length); // in meters

private:
    int length;
};

#endif // MOVE_H
