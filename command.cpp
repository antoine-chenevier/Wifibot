#include "command.h"

void Command::start(float god, float dod) {
    init_god = god;
    init_dod = dod;
}

void Command::update(float god, float dod) {
    current_god = god;
    current_dod = dod;
}
