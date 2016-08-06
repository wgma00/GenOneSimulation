#include "battle.h"
#include <algorithm> // Will use for std::min and std::max
#include <cmath>

double getTypeEffect(Move move, Type type) {
    return typeChart[move.type, type];
}

int getDamage(Move move, Pokemon poke1, Pokemon poke2, bool crit, double roll) {
    bool STAB = isSTAB(poke1, move);
    int critboost = crit ? 2 : 1;

    return std::floor(getDamage(move, poke1, poke2, STAB) * critboost * roll);
}

double getDamage(Move move, Pokemon poke1, Pokemon poke2, bool STAB) {
    double boost = STAB ? 1.5 : 1;
    bool phys = isPhysical(move);
    int atk = phys ? poke1.atk : poke1.spc;
    int def = phys ? poke2.def : poke2.spc;
    int atkmod, defmod;
    double effect = getTypeEffect(move, poke2.type1())
            * getTypeEffect(move, poke2.type2());

    if (phys) {
        atkmod = poke1.atkmod() > -1 ? (atkmod + 2) / 2.0 : 2.0 / (2 - atkmod);
        defmod = poke2.defmod() > -1 ? (defmod + 2) / 2.0 : 2.0 / (2 - defmod);
    } else {
        atkmod = poke1.spcmod() > -1 ? (atkmod + 2) / 2.0 : 2.0 / (2 - atkmod);
        defmod = poke2.spcmod() > -1 ? (defmod + 2) / 2.0 : 2.0 / (2 - defmod);
    }

    atk *= atkmod;
    atk = atkmod >= 1 ? std::min(atk, 999) : std::max(atk, 1);
    def *= defmod;
    def = defmod >= 1 ? std::min(def, 999) : std::max(def, 1);

    // Formula is (((2 * Level + 10)/250) * (Atk/Def) * BP + 2) * Modifiers
    // Modifiers = STAB * Type * Crit * roll
    return (.84 * (atk/def) * move.bp + 2) * boost * effect;
}

bool isPhysical(Move move) {
    return move.type < 8; // 8 comes from the order of types in the type enum
}

bool isSTAB(Pokemon pokemon, Move move) {
    return pokemon.type1() == move.type || pokemon.type2() == move.type;
}