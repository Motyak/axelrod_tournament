#include <duel.h>

#include <iostream>

Scores duel(int coupJ1, int coupJ2, const MatriceGains& matriceGains)
{
    // on combine les coups pour former la clé de la matrice des gains
    return matriceGains.at((coupJ1<<4) + coupJ2);
}

void afficher(const Scores& scores)
{
    std::cout << "J1: " << scores.first << std::endl;
    std::cout << "J2: " << scores.second << std::endl;
    if(scores.first == scores.second)
        std::cout << "Egalité" << std::endl;
    else
    {
        if(scores.first > scores.second)
            std::cout << "J1 ";
        else
            std::cout << "J2 ";
        std::cout << "a gagné!" << std::endl;
    }
}
