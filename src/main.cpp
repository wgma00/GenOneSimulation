"../include/battle.h"
"../include/move.h"
"../include/pokedata.h"
"../include/pokemon.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <vector>

double battle(std::vector<Pokemon> team1, std::vector<Pokemon> team2) {
    while (team1.size() > 0 && team2.size() > 0) {
        double spe1 = team1[0].spe();
        double spe2 = team2[0].spe();
        double spemod1;
        double spemod2;
        int spemod;

        if (team1[0].paramod()) {
            spemod = team1[0].spemod();
            spemod1 = spemod > -1 ? (spemod + 2) / 4 : 2 / (4 - spemod);
        } else {
            spemod = team1[0].spemod();
            spemod1 = spemod > -1 ? (spemod + 2) / 2 : 2 / (2 - spemod);
        }
        if (team2[0].paramod()) {
            spemod = team2[0].spemod();
            spemod2 = spemod > -1 ? (spemod + 2) / 4 : 2 / (4 - spemod);
        } else {
            spemod = team2[0].spemod();
            spemod2 = spemod > -1 ? (spemod + 2) / 2 : 2 / (2 - spemod);
        }

        spe1 *= spemod1;
        spe1 = std::floor(spe1);
        spe1 = spemod1 >= 1 ? std::min(spe1, 999.) : std::max(spe2, 1.);
        spe2 *= spemod2;
        spe2 = std::floor(spe2);
        spe2 = spemod2 >= 1 ? std::min(spe2, 999.) : std::max(spe2, 1.);

        if (spe1 > spe2) {
            exActions(team1, team2);
        } else if (spe1 < spe2) {
            exActions(team2, team1);
        } else {
            srand(time(NULL));
            int coinflip = rand() % 2;
            coinflip == 1 ? exActions(team1, team2) : exActions(team2, team1);
        }
    }

    return team1.size() > 0 ? 1.0 : 0.0;
}

void exActions(std::vector<Pokemon> &first, std::vector<Pokemon> &second) {
    srand(time(NULL));
    int choice = rand() % first.moves().size() + first.size();
    int basespe = 0; //placeholder
    int critchance = rand() % 512;
    bool crit = critchance < basespe;
    int acc = rand() % 100;
    int choice = handleClamp(first); // Clamp checker to prevent switching if clamped
    int damage;

    // First poke's moves
    if (choice <= first.moves().size() && first[0].canMove()) {
        if (first.moves().size() == 0) { //struggle
            Move m("struggle,100,50,attack,10,TRUE,recoil,100 none,none,normal");
            damage = getDamage(m, first[0], second[0], crit, (((rand() % 16) + 85)) / 100);
            int recoil = std::floor(damage / 2.0);
            first[0].setCurrentHP(first[0].currentHP() - recoil);
            second[0].setCurrentHP(second[0].currentHP() - damage);
            handleFaint(first); // Faster side KOed
            handleFaint(second); // Slower side KOed
        } else { // One of the mon's moves
            if (accuracy < first[0].moves().at(choice).get_accuracy()) {
                Move m = first.[0].moves().at(choice);

                // Time for a crapton of conditionals...
                if (m.get_category() == "attack") {
                    damage = getDamage(m, first[0], second[0], crit, (((rand() % 16) + 85)) / 100);

                    switch (m.get_name()) {
                        case "hyperbeam": {
                            break;
                        }
                        case "nightshade": {
                            break;
                        }
                        case "doubleedge": {
                            break;
                        }
                        case "megadrain": {
                            break;
                        }
                        case default: {
                            break;
                        }
                    }

                    second[0].setCurrentHP(second[0].currentHP() - damage);
                    handleFaint(second); // Slower side KOed
                    m.set_pp(m.get_pp() - 1);
                } else if (move.get_category() == "special") {

                } else {

                }
            }
        }
    } else {
        // switch
        handleSwitch(first, choice);
    }

    basespe = 0; //placeholder
    critchance = rand() % 512;
    crit = critchance < basespe;
    acc = rand() % 100;
    choice = handleClamp(second); // Clamp checker to prevent switching if clamped

    // Second poke's moves
    if (choice <= second.moves().size() && second[0].canMove()) {
        if (second.moves().size() == 0) { //struggle
            Move m("struggle,100,50,attack,10,TRUE,recoil,100 none,none,normal");
            damage = getDamage(m, second[0], first[0], crit, ((rand() % 16) + 85)) / 100;
            int recoil = std::floor(damage / 2.0);
            second[0].setCurrentHP(first[0].currentHP() - recoil);
            first[0].setCurrentHP(second[0].currentHP() - damage);
            handleFaint(first); // Faster side KOed
            handleFaint(second); // Slower side KOed
        } else { // One of the mon's moves
            if (accuracy < second[0].moves().at(choice).get_pp()) {

            }
        }
    } else {
        // switch
        handleSwitch(second, choice);
    }
}

void handleFaint(std::vector<Pokemon> &team) {
    srand(time(NULL));

    if (team[0].currentHP() <=0) { // Slower side KOed
        team.erase(team.begin());
        if (team.size() == 0) return;
        int replacement = rand() % team.size();
        Pokemon temp = team[0];
        team[0] = team[replacement];
        team[replacement] = temp;
    }
}

void handleSwitch(std::vector<Pokemon> &team, int choice) {
    srand(time(NULL));
    int newchoice = choice - team[0].moves().size();

    if (newchoice == 0) {
        newchoice = (rand() % (team.size() - 1)) + 1;
    }
    if (team[0].status() != PARALYSIS && team[0].paramod()) {
        team[0].setParaMod(false);
    }
}

int handleClamp(std::vector<Pokemon> &team) {
    int choice;

    if (team[0].clampturns() == 0) {
        choice = rand() % team[0].moves().size() + team.size();
    } else {
        choice = rand() % team[0].moves().size();
        team[0].setClampTurns(team[0].clampturns() - 1);
    }

    return choice;
}

std::vector<Pokemon> getBestTeam(std::vector<std::vector<Pokemon>> teams) {
    //place teams into map and pick the mode
    return NULL;
}

int main (int argc, char **argv) {
    std::vector<std::vector<Pokemon>> simTeams;
    std::vector<double> alphas;
    std::vector<std::<vector<Pokemon>> bestTeams;

    for (int i = 0; i < simTeams.size(); i++) {
        std::vector<std::vector<double>> confInts;
        std::vector<double> outcomes;
        double alpha = 0.01;
        int numBattles = 0;

        do {
            for (int k = 0; k < simTeams.size(); k++) {
                outcomes[k] = battle(simTeams[k], simTeams[i]);
                // 1 if win 0 if loss
            }

            numBattles++;
            highLowBound = INT_MIN;
            lowHighBound = INT_MAX;
            std::vector<Pokemon> supTeam; // Lowest upper bound team

            for (int k = 0; k < simTeams.size(); k++) {
                double M = outcomes[k] / numBattles;
                double p = M;
                int n = numBattles;
                double r = 0.5;
                confInts[k][0] = M - z(1 - r * alpha) * std::sqrt(p * (1 - p) / n);
                confInts[k][1] = M - z(alpha - r * alpha) * std::sqrt(p * (1 - p) / n);
                //[M-z(1-r*alpha)*sqrt(p(1-p)/n), M-z(alpha-r*alpha)sqrt(p(1-p)/n)] //[lower bound, upper bound]

                if (confInts[k][0] > highLowBound) {
                    highLowBound = confInts[k][0];
                }
                if (confInts[k][1] < lowHighBound) {
                    lowHighBound = confInts[k][1];
                    supTeam = simTeams[k];
                }
            }

            alpha += 0.01;
        } while (highLowBound <= lowHighBound)

        alphas[i] = alpha;
        bestTeams[i] = supTeam;
    }

    std::vector<Pokemon> bestTeam = getBestTeam(bestTeams);
    double confidence = 1;

    for (int i = 0; i < alphas.size(); i++) {
        confidence *= 1 - alphas[i];
    }

    // Do somethnig with bestTeam

    return 0;
}