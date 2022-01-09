#include <duel.h>

#include <iostream>

Scores duel(int coupJ1, int coupJ2, const MatriceGains& matriceGains)
{
    // on combine les coups pour former la clé de la matrice des gains
    return matriceGains.at((coupJ1<<4) + coupJ2);
}

void afficher(const Scores& scores)
{
    const float& s1(scores.first), s2(scores.second);
    std::cout << "J1: " << s1 << '\n' << "J2: " << s2 << '\n'
              << (s1==s2?"Égalité":std::string(s1>s2?"J1 ":"J2 ")+"a gagné!")
              << std::endl;
}
