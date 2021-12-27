#ifndef JOUEUR_H
#define JOUEUR_H

#include "axelrod.h"

#include <map>
#include <stack>

using Id = unsigned;
using Historique = std::stack<Coup>;

class Joueur
{
    unsigned id;

  protected:
    std::map<Id,Historique> historique;
    std::map<Id,Coup> prochainCoup;
    std::map<Id,Score> score;

    // template method, appelée dans 'ajouterResultat'
    virtual void ajouterProchainCoup(Id adversaire, Coup coupAdverse) = 0;

  public:
    explicit Joueur(Id);
    Coup jouer(Id adversaire);
    void ajouterResultat(Id adversaire, Coup coupAdverse);
    std::map<Id,Score> getScores() const;
    unsigned getId() const;
};

#endif
