#include <string>
#include "pokemon.h"
#include "bigdecimal.h"
#ifndef STATE_H
#define STATE_H

class State {
    private:
        Pokemon team1[6];
        Pokemon team2[6];
        BigDecimal prob; // placeholder for high precision class

    public:
        State();
        State(Pokemon *team1, Pokemon *team2);
        ~State();

        Pokemon *team1();
        Pokemon *team2();
        BigDecimal probability();

        void setTeam1(Pokemon *newTeam1);
        void setTeam2(Pokemon *newTeam2);
        void setProbability(BigDecimal newDecimal)

        std::string ToString();
};

#endif