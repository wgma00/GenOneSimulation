#include "pokedata.h"
#ifndef POKEMON_H
#define POKEMON_H

class Pokemon {
    private:
        Type type1, type2;
        Move move1, move2, move3, move4;
        int HP, Atk, Def, Spc, Spe;
        int modAtk, modDef, modSpc, modSpe;

    public:
        Type getType1();
        Type getType2();
        int getHP();
        int getAtk();
        int getDef();
        int getSpc();
        int getSpe();
};

#endif