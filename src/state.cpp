#include "state.h"

State::State() {

}

State::State(Pokemon *team1, Pokemon *team2) {

}

State::~State() {

}

Pokemon *State::team1() {
    return team1;
}

Pokemon *State::team2() {
    return team2;
}

void State::setTeam1(Pokemon *newTeam1) {
    team1 = newTeam1;
}

void State::setTeam2(Pokemon *newTeam2) {
    team2 = newTeam2;
}

std::string State::ToString() {

}