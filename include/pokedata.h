#ifndef POKEDATA_H
#define POKEDATA_H

enum Type {NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE,
        WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON, NEUTRAL};

enum Status {FREEZE, SLEEP, PARALYSIS, NONE};

double typeChart[16][16] = {
    {1, 1, 1, 1, 1, 0.5, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 1, 0.5, 0.5, 1, 2, 0.5, 0, 1, 1, 1, 1, 0.5, 2, 0, 1},
    {1, 2, 1, 1, 1, 0.5, 2, 1, 1, 1, 2, 0.5, 1, 1, 1, 1},
    {1, 1, 1, 0.5, 0.5, 0.5, 2, 0.5, 1, 1, 2, 1, 1, 1, 1, 1},
    {1, 1, 0, 2, 1, 2, 0.5, 1, 2, 1, 0.5, 2, 1, 1, 1, 1},
    {1, 0.5, 2, 1, 0.5, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    {1, 0.5, 0.5, 2, 1, 1, 1, 0.5, 0.5, 1, 2, 1, 2, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0.5, 2, 1, 0.5, 0.5, 2, 1, 1, 2, 0.5, 1},
    {1, 1, 1, 1, 2, 2, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 0.5, 1},
    {1, 1, 0.5, 0.5, 2, 2, 0.5, 1, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1},
    {1, 1, 2, 1, 0, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1},
    {1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1},
    {1, 1, 2, 1, 2, 1, 1, 1, 1, 0.5, 2, 1, 1, 0.5, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

#endif
Type to_move(std::string str){
    if(str == "normal")return NORMAL;
    if(str == "fighting")return FIGHTING;
    if(str == "flying")return FLYING;
    if(str == "poison")return POISON;
    if(str == "ground")return GROUND;
    if(str == "rock")return ROCK;
    if(str == "bug")return BUG;
    if(str == "ghost")return GHOST;
    if(str == "fire")return FIRE;
    if(str == "water")return WATER;
    if(str == "grass")return GRASS;
    if(str == "electric")return ELECTRIC;
    if(str == "psychic")return PSYCHIC;
    if(str == "ice")return ICE;
    if(str == "dragon")return DRAGON;
    return "NULLPTR - to_move"
}
