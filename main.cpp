#include <map>
#include <utility>
#include <iostream>

using Scores = std::pair<float,float>; // J1 et J2
using MatriceGains = std::map<unsigned char,Scores>; // Coup vers Scores

namespace PierreFeuilleCiseaux
{
    enum Coup { PIERRE, FEUILLE, CISEAUX };

    MatriceGains matriceGains = {
        { 0b00000000, {0.f, 0.f} }, // PIERRE_PIERRE
        { 0b00000001, {0.f, 1.f} }, // PIERRE_FEUILLE
        { 0b00000010, {1.f, 0.f} }, // PIERRE_CISEAUX
        { 0b00010000, {1.f, 0.f} }, // FEUILLE_PIERRE
        { 0b00010001, {0.f, 0.f} }, // FEUILLE_FEUILLE
        { 0b00010010, {0.f, 1.f} }, // FEUILLE_CISEAUX
        { 0b00100000, {0.f, 1.f} }, // CISEAUX_PIERRE
        { 0b00100001, {1.f, 0.f} }, // CISEAUX_FEUILLE
        { 0b00100010, {0.f, 0.f} }  // CISEAUX_CISEAUX
    };
};

namespace DilemnePrisonnier
{
    enum Coup { COOPERE, TRAHIT };

    MatriceGains matriceGains = {
        { 0b00000000, {3.f, 3.f} }, // COOPERE_COOPERE
        { 0b00000001, {0.f, 5.f} }, // COOPERE_TRAHIT
        { 0b00010000, {5.f, 0.f} }, // TRAHIT_COOPERE
        { 0b00010001, {1.f, 1.f} }  // TRAHIT_TRAHIT
    };
};

struct Resultat
{
    int coupAdverse;
    float score;
};

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

int main()
{
    // auto res = duel(PierreFeuilleCiseaux::CISEAUX, PierreFeuilleCiseaux::PIERRE, PierreFeuilleCiseaux::matriceGains);
    auto res = duel(DilemnePrisonnier::TRAHIT, DilemnePrisonnier::COOPERE, DilemnePrisonnier::matriceGains);
    
    afficher(res);
}
