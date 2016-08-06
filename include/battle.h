#ifndef BATTLE_H
#define BATTLE_h

#include "../include/move.h"
#include "../include/pokedata.h"
#include "../include/pokemon.h"

double getTypeEffect(Move move, Type type);

int getDamage(Move move, Pokemon poke1, Pokemon poke2, bool crit, double roll);

double getDamage(Move move, Pokemon poke1, Pokemon poke2, bool STAB);

bool isPhysical(Move move);

bool isSTAB(Pokemon pokemon, Move move);

#endif
