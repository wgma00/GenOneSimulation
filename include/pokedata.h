#ifndef PDATA_H
#define PDATA_H
enum Type = {NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE,
        WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON};

struct Move {
    int bp;
    int pp;
    int accuracy;
    Type type;
};

#endif