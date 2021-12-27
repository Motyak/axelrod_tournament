#ifndef DILEMNE_PRISONNIER_H
#define DILEMNE_PRISONNIER_H

#include "duel.h"

namespace DilemnePrisonnier
{
    enum Coup { COOPERE, TRAHIT };

    std::pair<Resultat,Resultat> duel(int coupJ1, int coupJ2);
};

#endif