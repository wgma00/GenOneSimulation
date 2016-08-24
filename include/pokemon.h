#ifndef POKEMON_H
#define POKEMON_H

#include "../include/move.h"
#include "../include/pokedata.h"
#include <string>
#include <vector>

class Pokemon {
    private:
        enum TypeOrder {TYPE1, TYPE2};
        enum MoveOrder {MOVE1, MOVE2, MOVE3, MOVE4};
        enum RegStat {HP, ATK, DEF, SPC, SPE};
        enum ModStat {MODATK, MODDEF, MODSPC, MODSPE};

        std::vector<Type> types_;
        std::vector<Move*> moves_;
        std::vector<int> stats_;
        std::vector<int> mods_;

        Pkmn name_;
        Status condition_;
        int currentHP_;
        bool confused_;
        bool rested_;
        bool paraMod_;
        int baseSpe_;
        int clampTurns_;
        int sleepTurns_;
        int counterDamage_;

    public:
        Pokemon();
        Pokemon(Pkmn name, std::vector<Type> types, std::vector<Move*> moves,
                std::vector<int> stats, std::vector<int> mods, Status status,
                int baseSpe);
        Pokemon(std::string data, std::vector<Move*>moves);
        ~Pokemon();

        Type type1();
        Type type2();
        Move* move1();
        Move* move2();
        Move* move3();
        Move* move4();
        std::vector<Move*> getMoves();
        int getHP();
        int getCurrentHP();
        int getAtk();
        int getDef();
        int getSpc();
        int getSpe();
        int getAtkmod();
        int getDefmod();
        int getSpcmod();
        int getSpemod();
        Pkmn getName();
        Status getCondition();
        bool isConfused();
        bool isRested();
        bool getParamod();
        int getBasespe();
        int getClampturns();
        int getSleepturns();
        int getCounterDamage();

        void setType1(Type newType);
        void setType2(Type newType);
        void setMove1(Move* newMove);
        void setMove2(Move* newMove);
        void setMove3(Move* newMove);
        void setMove4(Move* newMove);
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
        void setName(Pkmn name);
        void setStatus(Status newStatus);
        void setConfusion(bool newConfusion);
        void setRested(bool newRested);
        void setParaMod(bool newParaMod);
        void setBaseSpe(int newBaseSpe);
        void setClampTurns(int newClampTurns);
        void setSleepTurns(int newSleepTurns);
        void setCounterDamage(int newCounterDamage);
};

#endif
