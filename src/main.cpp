#include <PierreFeuilleCiseaux.h>
#include <DilemnePrisonnier.h>

#include <iostream>

using namespace PierreFeuilleCiseaux;
using namespace DilemnePrisonnier;
using namespace DilemnePrisonnierItere;

int main()
{
    /* Création de l'historique */
    std::vector<DilemnePrisonnier::Coup> historique;
    historique.push_back(COOPERE);
    // historique.push_back(TRAHIT);

    std::cout << coopereToujours(historique) << std::endl;
    std::cout << trahitToujours(historique) << std::endl;
    std::cout << oeilPourOeil(historique) << std::endl;
    
}
