#ifndef BATTLE_H
#define BATTLE_h
#include "pokedata.h"

double getTypeEffect(Move move, Type type);

int getDamage(Move move, Pokemon poke1, Pokemon poke2, bool crit, double roll);

int getDamage(Move move, Pokemon poke1, Pokemon poke2, bool STAB);

bool isPhysical(Move move);

bool isSTAB(Pokemon pokemon, Move move);

#endif