#include "battle.h"

double getTypeEffect(Move move, std::vector<Type*> types) {
    return getTypeEffect(move, types->at(1)) * getTypeEffect(move, types->at(2));
}

double getTypeEffect(Move move, Type type) {
    return typeChart[move.type, type];
}

int getDamage(Move move, Pokemon pokemon, bool STAB, bool crit, double roll) {
    if (crit) {

    } else {

    }

    return 0;
}

double getBaseDamage(Move move, Pokemon pokemon, bool STAB) {
    if (STAB) {

    } else {

    }

    return 0.0;
}

bool isPhysical(Move move) {
    return move.type < 8;
}

bool isNeutral(Move move) {
    return move.type == Type.NEUTRAL;
}