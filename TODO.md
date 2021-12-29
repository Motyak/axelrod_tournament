# TODO

- [x] Coder un duel:
Fonction qui prend en paramètre deux coups (int/enum)
ainsi qu'une matrice des gains sous la forme d'un unsigned char
(4 premiers bits pour le coup du joueur 1 et les 4 derniers pour
le joueur 2). La fonction retourne une paire de float représentant
les scores du joueur 1 et 2.
La fonction doit pouvoir marcher avec en exemple un duel de
pierre-feuille-ciseaux (3 coups possibles) et un dilemne du prisonnier
(2 coups possibles).

- [ ] Pouvoir lire une matrice des gains à partir d'un fichier
(on mettrait juste le nom du fichier dans lequel lire la matrice
format texte)

- [x] Coder les stratégies du dilemne du prisonnier itéré:
Fonctions qui prennent en entrée un historique de coups (int/enum)
et retourne une probabilité de coopérer (entre 0 et 1).

- [x] Coder un Joueur qui possède une stratégie, un score et un historique

- [x] Coder une fonction qui prend en paramètre un joueur
et retourne un coup en fonction de sa stratégie et de son historique

- [x] Coder une fonction qui prend en paramètre deux joueurs par référence
et qui met à jour leur score et historique respectif en fonction de
leur stratégie.

# NOTES

