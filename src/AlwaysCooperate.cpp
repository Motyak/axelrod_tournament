#include "AlwaysCooperate.h"

AlwaysCooperate::AlwaysCooperate(Id adversaire) : Joueur(adversaire){}

void AlwaysCooperate::ajouterProchainCoup(Id adversaire, Coup _)
{
    this->prochainCoup[adversaire] = Coup::COOPERERATION;
}
