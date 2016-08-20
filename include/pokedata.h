#ifndef POKEDATA_H
#define POKEDATA_H

enum Type {NORMAL, FIGHTING, FLYING, POISON, GROUND, ROCK, BUG, GHOST, FIRE,
        WATER, GRASS, ELECTRIC, PSYCHIC, ICE, DRAGON, NEUTRAL};

enum Pkmn {ALAKAZAM, CLOYSTER, CHANSEY, EXEGGUTOR, GENGAR, GOLEM, JOLTEON,
              JYNX, LAPRAS, RHYDON, SLOWBRO, SNORLAX, STARMIE, TAUROS, ZAPDOS,
              NULL_PKMN}

enum Status {FREEZE, SLEEP, PARALYSIS};

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


Type to_type(std::string str){
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
    return NEUTRAL; 
}

Pokemon to_pokemon(std::string str){
    if(str == "alakazam") return ALAKAZAM;
    if(str == "cloyster") return CLOYSTER;
    if(str == "chansey") return CHANSEY;
    if(str == "exeggutor") return EXEGGUTOR;
    if(str == "gengar") return GENGAR;
    if(str == "golem") return GOLEM;
    if(str == "jolteon") return JOLTEON;
    if(str == "jynx") return JYNX;
    if(str == "lapras") return LAPRAS;
    if(str == "rhydon") return RHYDON;
    if(str == "slowbro") return SLOWBRO;
    if(str == "snorlax") return SNORLAX;
    if(str == "starmie") return STARMIE;
    if(str == "tauros") return TAUROS;
    if(str == "zapdos") return ZAPDOS;
    return NULL_PKMN; // this is likely an error 
}

#endif
