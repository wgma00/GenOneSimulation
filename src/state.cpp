#include "state.h"
#include <vector>

State::State(Pokemon *team1, Pokemon *team2) {

}

State::~State() {

}

std::vector<Pokemon> State::team1() {
    return team1;
}

std::vector<Pokemon> State::team2() {
    return team2;
}

void State::setTeam1(std::vector<Pokemon*> newTeam1) {
    team1 = newTeam1;
}

void State::setTeam2(std::vector<Pokemon*> newTeam2) {
    team2 = newTeam2;
}

std::string State::ToString() {

}
