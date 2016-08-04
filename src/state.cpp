#include "state.h"
#include <vector>

State::State(std::vector<Pokemon*> team1, std::vector<Pokemon*> team2) {
    for (int i = 0; i < 6; i++) {
        team1_.at(i) = team1->at(i);
        team2_.at(i) = team2->at(i);
    }
}

State::~State() {

}

std::vector<Pokemon> State::team1() {
    return team1_;
}

std::vector<Pokemon> State::team2() {
    return team2_;
}

void State::setTeam1(std::vector<Pokemon*> newTeam1) {
    for (int i = 0; i < 6; i++) {
        team1_.at(i) = newTeam1->at(i);
    }
}

void State::setTeam2(std::vector<Pokemon*> newTeam2) {
    for (int i = 0; i < 6; i++) {
        team2_.at(i) = newTeam2->at(i);
    }
}

std::string State::ToString() {

}
