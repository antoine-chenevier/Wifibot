#include "rotation.h"

Rotation::Rotation(int angle) : angle(angle)
{
}


void Rotation::start(float god, float dod, MyRobot* robot) {
    init_god = god;
    init_dod = dod;
}

bool Rotation::update(float god, float dod, MyRobot* robot) {

}
