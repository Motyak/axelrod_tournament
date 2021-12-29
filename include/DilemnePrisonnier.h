#ifndef DILEMNE_PRISONNIER_H
#define DILEMNE_PRISONNIER_H

#include "duel.h"

#include <vector>

namespace DilemnePrisonnier
{
    enum Coup { COOPERE, TRAHIT };

    Scores duel(int coupJ1, int coupJ2);

    const MatriceGains matriceGains = {
        { 0b00000000, {3.f, 3.f} }, // COOPERE_COOPERE
        { 0b00000001, {0.f, 5.f} }, // COOPERE_TRAHIT
        { 0b00010000, {5.f, 0.f} }, // TRAHIT_COOPERE
        { 0b00010001, {1.f, 1.f} }  // TRAHIT_TRAHIT
    };
};

namespace DilemnePrisonnierItere
{
    struct Joueur
    {
        float (*strategie)(const std::vector<DilemnePrisonnier::Coup>&);
        float score = 0.f;
        std::vector<DilemnePrisonnier::Coup> historique = std::vector<DilemnePrisonnier::Coup>();
    };

    DilemnePrisonnier::Coup faireJouer(const Joueur&);
    void faireAffronter(Joueur&, Joueur&);

    /* strategies */
    float coopereToujours(const std::vector<DilemnePrisonnier::Coup>& historique);
    float trahitToujours(const std::vector<DilemnePrisonnier::Coup>& historique);
    float oeilPourOeil(const std::vector<DilemnePrisonnier::Coup>& historique);
    float aleatoire(const std::vector<DilemnePrisonnier::Coup>& historique);
};

#endif