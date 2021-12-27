#include "AlwaysDefect.h"

AlwaysDefect::AlwaysDefect(Id adversaire) : Joueur(adversaire){}

void AlwaysDefect::ajouterProchainCoup(Id adversaire, Coup coupAdverse)
{
    this->prochainCoup[adversaire] = Coup::TRAHISON;
}
