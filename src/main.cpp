#include "Tournoi.h"
#include "AlwaysCooperate.h"
#include "AlwaysDefect.h"
#include "TitForTat.h"

int main()
{
    std::vector<Joueur*> JOUEURS = {
        new AlwaysCooperate(10U),
        new AlwaysDefect(11U),
        new TitForTat(12U)
    };

    const unsigned NB_DE_TOURS = 3U;

    const MatriceDesGains GAINS = {
        std::pair{3., 3.},  // COOP_COOP
        std::pair{1., 1.},  // TRAHI_TRAHI
        std::pair{0., -5.}, // COOP_TRAHI
        std::pair{-5., 0.}  // TRAHI_COOP
    };

    Tournoi tournoi(Tournoi::Regles{NB_DE_TOURS, GAINS}, JOUEURS);

    

}

