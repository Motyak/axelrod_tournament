#include <PierreFeuilleCiseaux.h>
#include <DilemnePrisonnier.h>

#include <iostream>

using namespace PierreFeuilleCiseaux;
using namespace DilemnePrisonnier;

int main()
{
    {
        std::cout << "Ciseaux VS Pierre" << std::endl;
        auto res = PierreFeuilleCiseaux::duel(CISEAUX, PIERRE);
        afficher(res);
        std::cout << "-----------------" << std::endl << std::endl;
    }

    {
        std::cout << "Trahit VS Coopere" << std::endl;
        auto res = DilemnePrisonnier::duel(TRAHIT, COOPERE);
        afficher(res);
    }
}
