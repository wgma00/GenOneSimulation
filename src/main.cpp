"../include/battle.h"
"../include/pokedata.h"
"../include/pokemon.h"
#include <climits>
#include <vector>

double battle(std::vector<Pokemon> team1, std::vector<Pokemon> team2) {
    return 0.0;
}

std::vector<Pokemon> getBestTeam(std::vector<std::vector<Pokemon>> teams) {
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
                confInts[k][0] = 0;
                confInts[k][1] = 0;

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
    return 0;
}