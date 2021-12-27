#ifndef PIERRE_FEUILLE_CISEAUX_H
#define PIERRE_FEUILLE_CISEAUX_H

#include "duel.h"

namespace PierreFeuilleCiseaux
{
    enum Coup { PIERRE, FEUILLE, CISEAUX };

    std::pair<Resultat,Resultat> duel(int coupJ1, int coupJ2);
};

#endif
