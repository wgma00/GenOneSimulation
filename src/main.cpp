"../include/battle.h"
"../include/move.h"
"../include/pokedata.h"
"../include/pokemon.h"
#include <climits>
#include <cmath>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <vector>

double battle(std::vector<Pokemon> team1, std::vector<Pokemon> team2) {

    if (team1[0].spe() > team2[0].spe()) {
        exActions(team1, team2);
    } else if (team1[0].spe() < team2[0].spe()) {
        exActions(team2, team1);
    } else {
        srand(time(NULL));
        int coinflip = rand() % 2;
        coinflip == 1 ? exActions(team1, team2) : exActions(team2, team1);
    }

    return 0.0;
}

void exActions(std::vector<Pokemon> first, std::vector<Pokemon> second) {
    srand(time(NULL));
    int choice = rand() % first.moves().size() + first.size();
    int basespe = 0; //placeholder
    int critchance = rand() % 512;
    bool crit = critchance < basespe;
    int acc = rand() %
    int damage;

    if (choice <= first.moves().size() && first[0].canMove()) {
        if (first.moves().size() == 0) { //struggle
            Move m("struggle,100,50,attack,10,TRUE,recoil,100 none,none,normal");
            damage = getDamage(m, first[0], second[0], crit, ((rand() % 16) + 15)) / 100;
            int recoil = std::floor(damage / 2.0);
            first[0].setCurrentHP(first[0].currentHP() - recoil);
            second[0].setCurrentHP(second[0].currentHP() - damage);

            if (first[0].currentHP() <= 0) { // Faster side KOed

            }
            if (first[0].currentHP() <=0) { // Slower side KOed

            }
        } else { // One of the mon's moves

        }
    } else { // switch
        choice = choice - first.moves().size();

        if (choice == 0) {
            choice = (rand() % (first.size() - 1)) + 1;
        }

        Pokemon temp = first[0];
        first[0] = first[choice];
        first[choice] = temp;
    }

    // Second poke's moves
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
                confInts[k][1] = M - a(alpha - r * alpha) * std::sqrt(p * (1 - p) / n);
                //[M-z(1-r*alpha)*sqrt(p(1-p)/n), M-a(alpha-r*alpha)sqrt(p(1-p)/n)] //[lower bound, upper bound]

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