#include <DilemnePrisonnier.h>

#include <aleat.h>
#include <algorithm>
#include <iostream>

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
    Scores scores = DilemnePrisonnier::duel(coup_j1, coup_j2);

    /* on change l'état du joueur1 */
    j1.score += scores.first;
    j1.historique.push_back(coup_j2);

    /* on change l'état du joueur2 */
    j2.score += scores.second;
    j2.historique.push_back(coup_j1);
}

DilemnePrisonnierItere::Tournoi DilemnePrisonnierItere::creerTournoi(const std::map<std::string,Strategie>& joueurs)
{
    Tournoi tournoi;

    for(const auto& j: joueurs)
    {
        auto& nom = j.first;
        auto& strategie = j.second;
        tournoi.joueurs.push_back(Joueur{strategie, nom});
    }

    return tournoi;
}

static void DilemnePrisonnierItere::faireClassement(Tournoi& tournoi)
{
    // on fait une copie des joueurs
    std::vector<Joueur> joueurs = tournoi.joueurs;
    auto comparateur = [](const Joueur& j1, const Joueur& j2){ return j1.score > j2.score; };
    
    std::sort(joueurs.begin(), joueurs.end(), comparateur);
    
    for(const auto& j: joueurs)
        tournoi.classement.push_back(Tournoi::EntreeClassement{j.NOM, j.score});
}

void DilemnePrisonnierItere::jouer(Tournoi& tournoi, int nbDeRounds)
{
    auto premierJoueur = tournoi.joueurs.begin();
    auto dernierJoueur = tournoi.joueurs.end();

    for(int i = 1; i <= nbDeRounds; ++i)
        for(auto j1 = premierJoueur; dernierJoueur != j1; ++j1)
            for(auto j2 = j1; dernierJoueur != ++j2;)
                faireAffronter(*j1, *j2);

    faireClassement(tournoi);
}

void DilemnePrisonnierItere::afficher(const Tournoi::Classement& classement)
{
    const int nbDeJoueurs = classement.size();

    for(int i = 0; i < nbDeJoueurs; ++i)
    {
        auto& entree = classement.at(i);
        std::cout << (i + 1) << "° " + entree.nomJoueur << ": " << entree.scoreJoueur << std::endl;
    }
}

float DilemnePrisonnierItere::coopereToujours(const Historique& historique)
{
    return 1.f;
}

float DilemnePrisonnierItere::trahitToujours(const Historique& historique)
{
    return 0.f;
}

float DilemnePrisonnierItere::oeilPourOeil(const Historique& historique)
{
    if(historique.empty())
        return 1.f;
    return (historique.back() == DilemnePrisonnier::Coup::COOPERE ? 1.f : 0.f);
}

float DilemnePrisonnierItere::aleatoire(const Historique& historique)
{
    return 0.5f;
}

float DilemnePrisonnierItere::rancunier(const Historique& historique)
{
    if(historique.empty())
        return 1.f;
    for(const auto& coup: historique)
        if(coup == DilemnePrisonnier::Coup::TRAHIT)
            return 0.f;
    return 1.f;
}

float DilemnePrisonnierItere::oeilPourOeilGenereux(const Historique& historique)
{
    if(historique.size() < 2)
        return 1.f;
    if(historique.back() == DilemnePrisonnier::Coup::TRAHIT 
    && historique.at(historique.size()-2) == DilemnePrisonnier::Coup::TRAHIT)
        return 0.f;
}
