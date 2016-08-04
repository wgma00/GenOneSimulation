#ifndef POKEMON_H
#define POKEMON_H

#include "pokedata.h"
#include <string>
#include <vector>

class Pokemon {
    private:
        std::vector<Type> types_(2);
        std::vector<Move> moves_(4);
        std::vector<int> stats_(5);
        std::vector<int> mods_(4);
        enum typeOrder = {TYPE1, TYPE2};
        enum moveOrder = {MOVE1, MOVE2, MOVE3, MOVE4};
        enum regStat = {HP, ATK, DEF, SPC, SPE};
        enum modStat = {ATK, DEF, SPC, SPE};
        Status status_;
        bool isConfused_ = false;

    public:
        Pokemon(std::vector<Type*> types, std::vector<Move*> moves,
                std::vector<int*> stats, std::vector<int*> mods, Status status);
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
        int atkmod();
        int defmod();
        int spcmod();
        int spemod();
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
        void setAtkMod(int newModAtk);
        void setDefMod(int newModDef);
        void setSpcMod(int newModSpc);
        void setSpeMod(int newModSpe);
        void setStatus(Status newStatus);
        void setConfusion(bool confusion);

        void Attack(Pokemon pokemon, Move move);
        std::string ToString();

};

#endif