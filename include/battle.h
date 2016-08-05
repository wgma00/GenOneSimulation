#ifndef BATTLE_H
#define BATTLE_h
#include "pokedata.h"

double getTypeEffect(Move move, std::vector<Type*> types);

double getTypeEffect(Move move, Type type);

int getDamage(Move move, Pokemon pokemon, bool crit, double roll);

int getBaseDamage(Move move, Pokemon pokemon);

bool isPhysical(Move move);

bool isNeutral(Move move);

#endif