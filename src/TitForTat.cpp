#include "TitForTat.h"

TitForTat::TitForTat(Id adversaire) : Joueur(adversaire){}

void TitForTat::ajouterProchainCoup(Id adversaire, Coup coupAdverse)
{
    if(this->historique[adversaire].empty())
        this->prochainCoup[adversaire] = Coup::COOPERERATION;
    else
        this->prochainCoup[adversaire] = this->historique[adversaire].top();
}
