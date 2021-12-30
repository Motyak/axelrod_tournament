#include <PierreFeuilleCiseaux.h>

#include <aleat.h>

Scores PierreFeuilleCiseaux::duel(PierreFeuilleCiseaux::Coup coupJ1, PierreFeuilleCiseaux::Coup coupJ2)
{
    return ::duel(coupJ1, coupJ2, PierreFeuilleCiseaux::matriceGains);
}

void PierreFeuilleCiseauxItere::faireAffronter(PierreFeuilleCiseauxItere::Joueur& j1, PierreFeuilleCiseauxItere::Joueur& j2)
{
    PierreFeuilleCiseaux::Coup coup_j1 = j1.strategie(j1.historique);
    PierreFeuilleCiseaux::Coup coup_j2 = j2.strategie(j2.historique);
    Scores scores = duel(coup_j1, coup_j2, PierreFeuilleCiseaux::matriceGains);

    /* on change l'état du joueur1 */
    j1.score += scores.first;
    j1.historique.push_back(coup_j2);

    /* on change l'état du joueur2 */
    j2.score += scores.second;
    j2.historique.push_back(coup_j1);
}

PierreFeuilleCiseaux::Coup PierreFeuilleCiseauxItere::aleatoire(const std::vector<PierreFeuilleCiseaux::Coup>& historique)
{
    return (PierreFeuilleCiseaux::Coup)equiAleat(0, 2);
}

PierreFeuilleCiseaux::Coup PierreFeuilleCiseauxItere::repeteCoupAdverse(const std::vector<PierreFeuilleCiseaux::Coup>& historique)
{
    if(historique.empty())
        return aleatoire(historique);
    return historique.back();
}
