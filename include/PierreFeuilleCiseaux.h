#ifndef PIERRE_FEUILLE_CISEAUX_H
#define PIERRE_FEUILLE_CISEAUX_H

#include "duel.h"

namespace PierreFeuilleCiseaux
{
    enum Coup { PIERRE, FEUILLE, CISEAUX };

    Scores duel(int coupJ1, int coupJ2);

    const MatriceGains matriceGains = {
        { 0b00000000, {0.f, 0.f} }, // PIERRE_PIERRE
        { 0b00000001, {0.f, 1.f} }, // PIERRE_FEUILLE
        { 0b00000010, {1.f, 0.f} }, // PIERRE_CISEAUX
        { 0b00010000, {1.f, 0.f} }, // FEUILLE_PIERRE
        { 0b00010001, {0.f, 0.f} }, // FEUILLE_FEUILLE
        { 0b00010010, {0.f, 1.f} }, // FEUILLE_CISEAUX
        { 0b00100000, {0.f, 1.f} }, // CISEAUX_PIERRE
        { 0b00100001, {1.f, 0.f} }, // CISEAUX_FEUILLE
        { 0b00100010, {0.f, 0.f} }  // CISEAUX_CISEAUX
    };
};

#endif
