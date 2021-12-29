#include <PierreFeuilleCiseaux.h>

Scores PierreFeuilleCiseaux::duel(int coupJ1, int coupJ2)
{
    return ::duel(coupJ1, coupJ2, PierreFeuilleCiseaux::matriceGains);
}
