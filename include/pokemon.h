#ifndef POKEMON_H
#define POKEMON_H

#include "pokedata.h"
#include <string>
#include <vector>

class Pokemon {
    private:
        Type type1, type2;
        std::vector<Move> moves(4);
        std::vector<int> stats(5);
        std::vector<int> mods(4);
        enum regStat = {HP, ATK, DEF, SPC, SPE};
        enum modStat = {ATK, DEF, SPC, SPE};
        Status status;
        bool isConfused;

    public:
        Pokemon();
        Pokemon(Type *types, Move *moves, int *stats, int *mods, Status status);
        ~Pokemon();

        Type type1();
        Type type2();
        Move move1();
        Move move2();
        Move move3();
        Move move4();
        int hp();
        int atk();
        int def();
        int spc();
        int spe();
        std::vector<int> mods();
        Status status();
        bool confused();

        void setType1(Type newType);
        void setType2(Type newType);
        void setMove1(Move newMove);
        void setMove2(Move newMove);
        void setMove3(Move newMove);
        void setMove4(Move newMove);
        void setHP(int newHP);
        void setAtk(int newAtk);
        void setDef(int newDef);
        void setSpc(int newSpc);
        void setSpe(int newSpe);
        void setAtkMod(int newMod);
        void setDefMod(int newMod);
        void setSpcMod(int newMod);
        void setSpeMod(int newMod);
        void setStatus(Status newStatus);

        void Attack(Pokemon pokemon, Move move);
        std::string ToString();

};

#endif