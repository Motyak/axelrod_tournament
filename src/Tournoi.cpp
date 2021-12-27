#include "Tournoi.h"

Tournoi::Tournoi(Regles regles, std::vector<Joueur*> joueurs) : regles(regles), joueurs(joueurs){}

Tournoi::~Tournoi()
{
    for(const auto& j: this->joueurs)
        delete j;
}

void Tournoi::jouer()
{
    Coup coupJ1, coupJ2;
    for(int tour = 1; tour <= this->regles.nombreDeTours; ++tour)
    {
        for(const auto& j1 : this->joueurs)
        {
            for(const auto& j2 : this->joueurs)
            {
                if(j1->getId() == j2->getId())
                    continue;
                coupJ1 = j1->jouer(j2->getId());
                coupJ2 = j2->jouer(j1->getId());
                // pas fini
            }
        }
    }
}
