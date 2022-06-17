#include "move.h"
#include <math.h>

Move::Move(float length) : length(length)
{
}

void Move::start(float god, float dod, MyRobot* robot) {
    init_god = god;
    init_dod = dod;
    robot->forward();
}

bool Move::update(float god, float dod, MyRobot* robot) {
    float odo_offset = 2200 * length;
    if (abs((init_god + odo_offset) - god) < 0.1) {
        robot->stop();
        return true;
    } else {
        return false;
    }
}

