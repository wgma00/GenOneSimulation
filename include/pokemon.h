#include "pokedata.h"
#ifndef POKEMON_H
#define POKEMON_H

class Pokemon {
    private:
        Type type1, type2;
        Move move1, move2, move3, move4;
        int stats[5];
        int mods[4];
        enum modStat = {ATK, DEF, SPC, SPE};
        Status status;

    public:
        Type getType1();
        Type getType2();
        int getHP();
        int getAtk();
        int getDef();
        int getSpc();
        int getSpe();
        int *getMods();
        Status getStatus();
        void setType1(Type newType);
        void setType2(Type newType);
        void setHP(int newHP);
        void setAtk(int newAtk);
        void setDef(int newDef);
        void setSpc(int newSpc);
        void setSpe(int newSpe);
        void setAtkMod(int newMod);
        void setDefMod(int newMod);
        void setSpcMod(int newMod);
        void setSpcMod(int newMod);
        void attck(Pokemon pokemon, Move move);
        void setStatus(Status newStatus);
};

#endif