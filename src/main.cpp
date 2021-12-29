#include <DilemnePrisonnier.h>

#include <iostream>

using namespace DilemnePrisonnierItere;

int main()
{
    /* Faire rivaliser les stratégies 'aléatoire' et 'oeil pour oeil' sur 10 parties */
    const int NB_DE_PARTIES = 10;

    Joueur j1{&aleatoire}, j2{&oeilPourOeil};

    for(int i = 1; i <= NB_DE_PARTIES; ++i)
        faireAffronter(j1, j2);

    afficher({j1.score, j2.score});
}
