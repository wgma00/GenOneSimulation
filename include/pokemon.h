#ifndef POKEMON_H
#define POKEMON_H

#include "../include/move.h"
#include "../include/pokedata.h"
#include <string>
#include <vector>

class Pokemon {
    private:
        std::vector<Type> types;
        std::vector<Move> moves;
        std::vector<int> stats;
        std::vector<int> mods;
        enum typeOrder {TYPE1, TYPE2};
        enum moveOrder {MOVE1, MOVE2, MOVE3, MOVE4};
        enum regStat {HP, ATK, DEF, SPC, SPE};
        enum modStat {MODATK, MODDEF, MODSPC, MODSPE};
        Status condition;
        int currentHP;
        bool isConfused = false;
        Pkmn name;
        bool isRested = false;
        bool paraMod = false;
        int baseSpe;
        int clampTurns = 0;
        int sleepTurns = 0;
        int counterDamage = 0;

    public:
        Pokemon(Pkmn name, std::vector<Type> types, std::vector<Move> moves,
                std::vector<int> stats, std::vector<int> mods, Status status);
        ~Pokemon();

        Type type1();
        Type type2();
        Move move1();
        Move move2();
        Move move3();
        Move move4();
        std::vector<Move> moves();
        int hp();
        int currentHP();
        int atk();
        int def();
        int spc();
        int spe();
        int atkmod();
        int defmod();
        int spcmod();
        int spemod();
        Status status();
        Pkmn name();
        bool confused();
        bool rested();
        bool paramod();
        int basespe();
        int clampturns();
        int sleepturns();
        int counterdamage();

        void setType1(Type newType);
        void setType2(Type newType);
        void setMove1(Move newMove);
        void setMove2(Move newMove);
        void setMove3(Move newMove);
        void setMove4(Move newMove);
        void setHP(int newHP);
        void setCurrentHP(int newCurrentHP);
        void setAtk(int newAtk);
        void setDef(int newDef);
        void setSpc(int newSpc);
        void setSpe(int newSpe);
        void setAtkMod(int newModAtk);
        void setDefMod(int newModDef);
        void setSpcMod(int newModSpc);
        void setSpeMod(int newModSpe);
        void setStatus(Status newStatus);
        void setName(Pkmn name);
        void setConfusion(bool newConfusion);
        void setRested(bool newRested);
        void setParaMod(bool newParaMod);
        void setBaseSpe(int newBaseSpe);
        void setClampTurns(int newClampTurns);
        void setSleepTurns(int newSleepTurns);
        void setCounterDamage(int newCounterDamage);
};

#endif
