#include <PierreFeuilleCiseaux.h>

Scores PierreFeuilleCiseaux::duel(PierreFeuilleCiseaux::Coup coupJ1, PierreFeuilleCiseaux::Coup coupJ2)
{
    return ::duel(coupJ1, coupJ2, PierreFeuilleCiseaux::matriceGains);
}
