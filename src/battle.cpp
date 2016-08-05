#include "battle.h"
#include <algorithm> // Will use for std::min and std::max
#include <cmath>

double getTypeEffect(Move move, Type type) {
    return typeChart[move.type, type];
}

int getDamage(Move move, Pokemon pokemon, bool STAB, bool crit, double roll) {
    int critboost = crit ? 2 : 1;

    return std::floor(getBaseDamage(move, pokemon, STAB) * critboost * roll);
}

double getBaseDamage(Move move, Pokemon pokemon, bool STAB) {
    double boost = STAB ? 1.5 : 1;
    int atk = 1; // placeholder
    int def = 1; // placeholder
    double effect = getTypeEffect(move, pokemon.type1())
            * getTypeEffect(move, pokemon.type2());

    // Formula is (((2 * Level + 10)/250) * (Atk/Def) * BP + 2) * Modifiers
    // Modifiers = STAB * Type * Crit * roll
    return (.84 * (atk/def) * move.bp + 2) * boost * effect;
}

bool isPhysical(Move move) {
    return move.type < 8; // 8 comes from the order of types in the type enum
}

bool isNeutral(Move move) {
    return move.type == Type.NEUTRAL;
}

bool isSTAB(Pokemon pokemon, Move move) {
    return pokemon.type1() == move.type || pokemon.type2() == move.type;
}