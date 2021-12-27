#ifndef TOURNOI_H
#define TOURNOI_H

#include "Joueur.h"

#include <vector>

class Tournoi
{
  public:
    struct Regles
    {
        unsigned nombreDeTours;
        MatriceDesGains gains;
    };

  private:
    Regles regles;
    std::vector<Joueur*> joueurs;

public:
    explicit Tournoi(Regles, std::vector<Joueur*>);
    ~Tournoi();

    void jouer();
};

#endif