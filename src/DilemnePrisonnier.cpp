#include <DilemnePrisonnier.h>

#include <aleat.h>

Scores DilemnePrisonnier::duel(DilemnePrisonnier::Coup coupJ1, DilemnePrisonnier::Coup coupJ2)
{
    return ::duel(coupJ1, coupJ2, DilemnePrisonnier::matriceGains);
}

DilemnePrisonnier::Coup DilemnePrisonnierItere::faireJouer(const DilemnePrisonnierItere::Joueur& joueur)
{
    float probaCoop = joueur.strategie(joueur.historique);
    return (DilemnePrisonnier::Coup)!aleat(probaCoop);
}

void DilemnePrisonnierItere::faireAffronter(DilemnePrisonnierItere::Joueur& j1, DilemnePrisonnierItere::Joueur& j2)
{
    DilemnePrisonnier::Coup coup_j1 = DilemnePrisonnierItere::faireJouer(j1);
    DilemnePrisonnier::Coup coup_j2 = DilemnePrisonnierItere::faireJouer(j2);
    Scores scores = duel(coup_j1, coup_j2, DilemnePrisonnier::matriceGains);

    /* on change l'état du joueur1 */
    j1.score += scores.first;
    j1.historique.push_back(coup_j2);

    /* on change l'état du joueur2 */
    j2.score += scores.second;
    j2.historique.push_back(coup_j1);
}

float DilemnePrisonnierItere::coopereToujours(const std::vector<DilemnePrisonnier::Coup>& historique)
{
    return 1.f;
}

float DilemnePrisonnierItere::trahitToujours(const std::vector<DilemnePrisonnier::Coup>& historique)
{
    return 0.f;
}

float DilemnePrisonnierItere::oeilPourOeil(const std::vector<DilemnePrisonnier::Coup>& historique)
{
    if(historique.empty())
        return 1.f;
    return (historique.back() == DilemnePrisonnier::Coup::COOPERE ? 1.f : 0.f);
}

float DilemnePrisonnierItere::aleatoire(const std::vector<DilemnePrisonnier::Coup>& historique)
{
    return 0.5f;
}
