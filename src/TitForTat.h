#ifndef TIT_FOR_TAT_H
#define TIT_FOR_TAT_H

#include "Joueur.h"

struct TitForTat : public Joueur
{
    TitForTat(Id);
    void ajouterProchainCoup(Id adversaire, Coup coupAdverse) override;
};

#endif