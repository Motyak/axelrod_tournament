#include <PierreFeuilleCiseaux.h>
#include <DilemnePrisonnier.h>

#include <iostream>

int main()
{
    /* Faire rivaliser toutes les stratégies du dilemne du prisonnier itéré */
    /* dans un tournoi en 3 rounds */
    {
        using namespace DilemnePrisonnierItere;

        const int NB_DE_ROUNDS = 3;

        Tournoi tournoi = creerTournoi({
            {"ALL_C", &coopereToujours},
            {"ALL_D", &trahitToujours},
            {"E4E", &oeilPourOeil},
            {"RAND", &aleatoire}
        });

        jouer(tournoi, NB_DE_ROUNDS);

        afficherClassement(tournoi.classement);
    }

    std::cout << '\n'; //delim

    /* Faire rivaliser les stratégies 'aléatoire' et 'oeil pour oeil' sur 10 parties */
    /* du dilemne du prisonnier itéré */
    {
        using namespace DilemnePrisonnierItere;

        const int NB_DE_PARTIES = 10;

        Joueur j1{&aleatoire}, j2{&oeilPourOeil};

        for(int i = 1; i <= NB_DE_PARTIES; ++i)
            faireAffronter(j1, j2);

        afficher({j1.score, j2.score});
    }

    std::cout << '\n'; //delim

    /* Faire rivaliser les stratégies 'aléatoire' et 'répéte coup adverse' */
    /* sur 10 parties de pierre feuille ciseaux itéré */
    {
        using namespace PierreFeuilleCiseauxItere;

        const int NB_DE_PARTIES = 10;

        Joueur j1{&aleatoire}, j2{&repeteCoupAdverse};

        for(int i = 1; i <= NB_DE_PARTIES; ++i)
            faireAffronter(j1, j2);

        afficher({j1.score, j2.score});
    }
}
