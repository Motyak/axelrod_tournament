#ifndef DUEL_H
#define DUEL_H

#include <utility>
#include <map>

using Scores = std::pair<float,float>; // J1 et J2
using MatriceGains = std::map<unsigned char,Scores>; // Coup vers Scores

struct Resultat
{
    int coupAdverse;
    float score;
};

std::pair<Resultat,Resultat> duel(int coupJ1, int coupJ2, MatriceGains);

void afficher(std::pair<Resultat,Resultat>);

#endif
