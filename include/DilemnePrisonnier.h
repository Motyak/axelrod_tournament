#ifndef DILEMNE_PRISONNIER_H
#define DILEMNE_PRISONNIER_H

#include "duel.h"

#include <vector>

namespace DilemnePrisonnier
{
    enum Coup { COOPERE, TRAHIT };

    std::pair<Resultat,Resultat> duel(int coupJ1, int coupJ2);
};

namespace DilemnePrisonnierItere
{
    float coopereToujours(const std::vector<DilemnePrisonnier::Coup>& historique);

    float trahitToujours(const std::vector<DilemnePrisonnier::Coup>& historique);

    float oeilPourOeil(const std::vector<DilemnePrisonnier::Coup>& historique);
};

#endif