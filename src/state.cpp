#include "../include/state.h"
#include <vector>

State::State(std::vector<Pokemon> team1, std::vector<Pokemon> team2) {
    for (int i = 0; i < 6; i++) {
        this->t1.at(i) = team1.at(i);
        this->t2.at(i) = team2.at(i);
    }
}

State::~State() {

}

std::vector<Pokemon> State::team1() {
    return this->t1;
}

std::vector<Pokemon> State::team2() {
    return this->t2;
}

void State::setTeam1(std::vector<Pokemon> newTeam1) {
    for (int i = 0; i < 6; i++) {
        this->t1.at(i) = newTeam1.at(i);
    }
}

void State::setTeam2(std::vector<Pokemon> newTeam2) {
    for (int i = 0; i < 6; i++) {
        this->t2.at(i) = newTeam2.at(i);
    }
}

std::string State::ToString() {

}
