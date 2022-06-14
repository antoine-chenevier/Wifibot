#ifndef MOVE_H
#define MOVE_H

#include "command.h"

class Move : public Command
{
public:
    Move(float length); // in meters

    virtual bool is_done();
    virtual QString type();

private:
    float length;
};

#endif // MOVE_H
