#ifndef DUEL_H
#define DUEL_H

#include <utility>
#include <map>

using Scores = std::pair<float,float>; // J1 et J2
using MatriceGains = std::map<unsigned char,Scores>; // Coup vers Scores

Scores duel(int coupJ1, int coupJ2, const MatriceGains&);

void afficher(const Scores&);

#endif
