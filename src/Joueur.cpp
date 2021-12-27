#include "Joueur.h"

Joueur::Joueur(Id id) : id(id){}

Coup Joueur::jouer(Id adversaire)
{
    return this->prochainCoup[adversaire];
}

void Joueur::ajouterResultat(Id adversaire, Coup coupAdverse)
{
    this->historique[adversaire].push(coupAdverse);
    this->ajouterProchainCoup(adversaire, coupAdverse);
}

std::map<Id,Score> Joueur::getScores() const
{
    return this->score;
}

unsigned Joueur::getId() const
{
    return this->id;
}
