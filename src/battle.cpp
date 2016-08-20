#include "../include/battle.h"
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <time.h>

double getTypeEffect(Move move, Type type) {
    return typeChart[move.get_type(), type];
}

int getDamage(Move move, Pokemon poke1, Pokemon poke2, bool crit, double roll) {
    bool STAB = isSTAB(poke1, move);
    int critboost = crit ? 2 : 1;

    return std::floor(getDamage(move, poke1, poke2, crit, STAB) * critboost * roll);
}

double getDamage(Move move, Pokemon poke1, Pokemon poke2, bool crit, bool STAB) {
    double boost = STAB ? 1.5 : 1;
    bool phys = isPhysical(move);
    double atk = phys ? poke1.atk() : poke1.spc();
    double def = phys ? poke2.def() : poke2.spc();
    double atkmod, defmod;
    double effect = getTypeEffect(move, poke2.type1())
            * getTypeEffect(move, poke2.type2());

    if (phys) {
        atkmod = poke1.atkmod() > -1 ? (atkmod + 2) / 2 : 2 / (2 - atkmod);
        defmod = poke2.defmod() > -1 ? (defmod + 2) / 2 : 2 / (2 - defmod);
    } else {
        atkmod = poke1.spcmod() > -1 ? (atkmod + 2) / 2 : 2 / (2 - atkmod);
        defmod = poke2.spcmod() > -1 ? (defmod + 2) / 2 : 2 / (2 - defmod);
    }

    if (crit) {
        atkmod = 1;
        defmod = 1;
    }

    atk *= atkmod;
    atk = atkmod >= 1 ? std::min(atk, 999.) : std::max(atk, 1.);
    def *= defmod;
    def = defmod >= 1 ? std::min(def, 999.) : std::max(def, 1.);

    // Formula is (((2 * Level + 10)/250) * (Atk/Def) * BP + 2) * Modifiers
    // Modifiers = STAB * Type * Crit * roll
    return (.84 * (atk/def) * move.get_base_power() + 2) * boost * effect;
}

bool isPhysical(Move move) {
    return move.get_type() < 8; // 8 comes from the order of types in the type enum
}

bool isSTAB(Pokemon pokemon, Move move) {
    return pokemon.type1() == move.get_type() || pokemon.type2() == move.get_type();
}

bool hasValidMove(Pokemon pokemon) {
    return pokemon.move1().get_pp() + pokemon.move2().get_pp() + 
            pokemon.move3().get_pp() + pokemon.move4().get_pp() > 0;
}

bool canMove(Pokemon &pokemon) {
    srand(time(NULL));

    if (pokemon.status() == NONE) {
        return true;
    } else if (pokemon.status() == PARALYSIS) {
        return (rand() % 100) >= 25;
    } else if (pokemon.status() == SLEEP) {
        if (pokemon.sleepturns() == 0) {
            return true;
        }

        pokemon.setSleepTurns(pokemon.sleepturns() - 1);

        if (pokemon.sleepturns == 0) {
            pokemon.setStatus(NONE);
        }

        return false;
    } else {
        return false;
    }
}