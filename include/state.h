#ifndef STATE_H
#define STATE_H
#include <string>
#include "pokemon.h"

class State {
    private:
        Pokemon team1[6];
        Pokemon team2[6];
        //BigDecimal prob; placeholder for high precision class

    public:
        State();
        State(Pokemon *team1, Pokemon *team2);
        ~State();

        Pokemon *team1();
        Pokemon *team2();
        //BigDecimal probability(); placeholder for high precision class

        void setTeam1(Pokemon *newTeam1);
        void setTeam2(Pokemon *newTeam2);
        //void setProbability(BigDecimal newDecimal); placeholder for high precision class

        std::string ToString();
};

#endif