#ifndef ALWAYS_COOPERATE_H
#define ALWAYS_COOPERATE_H

#include "Joueur.h"

struct AlwaysCooperate : public Joueur
{
    AlwaysCooperate(Id);
    void ajouterProchainCoup(Id adversaire, Coup coupAdverse) override;
};

#endif