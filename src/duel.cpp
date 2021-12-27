#include <duel.h>

#include <iostream>

std::pair<Resultat,Resultat> duel(int coupJ1, int coupJ2, MatriceGains matriceGains)
{
    // on combine les coups pour former la clé de la matrice des gains
    Scores scores = matriceGains[(coupJ1<<4) + coupJ2];

    // on construit les résultats de chaque joueur
    Resultat res_J1 = {coupJ2, scores.first};
    Resultat res_J2 = {coupJ1, scores.second};

    return {res_J1, res_J2};
}

void afficher(std::pair<Resultat,Resultat> res)
{
    std::cout << "J1: " << res.first.score << std::endl;
    std::cout << "J2: " << res.second.score << std::endl;
    if(res.first.score == res.second.score)
        std::cout << "Egalité" << std::endl;
    else
    {
        if(res.first.score > res.second.score)
            std::cout << "J1 ";
        else
            std::cout << "J2 ";
        std::cout << "a gagné!" << std::endl;
    }
}
