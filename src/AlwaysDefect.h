#ifndef ALWAYS_DEFECT_H
#define ALWAYS_DEFECT_H

#include "Joueur.h"

struct AlwaysDefect : public Joueur
{
    AlwaysDefect(Id);
    void ajouterProchainCoup(Id adversaire, Coup coupAdverse) override;
};

#endif