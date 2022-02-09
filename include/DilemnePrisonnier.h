#ifndef DILEMNE_PRISONNIER_H
#define DILEMNE_PRISONNIER_H

#include "duel.h"

#include <vector>
#include <string>

namespace DilemnePrisonnier
{
    enum Coup { COOPERE, TRAHIT };

    Scores duel(Coup coupJ1, Coup coupJ2);

    const MatriceGains matriceGains = {
        { 0b00000000, {3.f, 3.f} }, // COOPERE_COOPERE
        { 0b00000001, {0.f, 5.f} }, // COOPERE_TRAHIT
        { 0b00010000, {5.f, 0.f} }, // TRAHIT_COOPERE
        { 0b00010001, {1.f, 1.f} }  // TRAHIT_TRAHIT
    };
};

namespace DilemnePrisonnierItere
{
    using Strategie = float(*)(const std::vector<DilemnePrisonnier::Coup>&);
    using Historique = std::vector<DilemnePrisonnier::Coup>;

    struct Joueur
    {
        Strategie strategie;
        std::string NOM = "";
        float score = 0.f;
        Historique historique = Historique();
        
    };

    DilemnePrisonnier::Coup faireJouer(const Joueur&);
    void faireAffronter(Joueur&, Joueur&);

    struct Tournoi
    {
        std::vector<Joueur> joueurs;

        struct EntreeClassement
        {
            std::string nomJoueur;
            float scoreJoueur;   
        };
        using Classement = std::vector<EntreeClassement>;
        Classement classement;
    };
    Tournoi creerTournoi(const std::map<std::string,Strategie>& joueurs);
    void jouer(Tournoi&, int nbDeRounds=1);
    static void faireClassement(Tournoi&);
    void afficher(const Tournoi::Classement&);

    /* strategies */
    float coopereToujours(const Historique&);
    float trahitToujours(const Historique&);
    float oeilPourOeil(const Historique&);
    float aleatoire(const Historique&);
};

#endif