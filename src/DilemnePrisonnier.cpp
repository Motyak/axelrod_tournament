#include <DilemnePrisonnier.h>

namespace DilemnePrisonnier
{
    const MatriceGains matriceGains = {
        { 0b00000000, {3.f, 3.f} }, // COOPERE_COOPERE
        { 0b00000001, {0.f, 5.f} }, // COOPERE_TRAHIT
        { 0b00010000, {5.f, 0.f} }, // TRAHIT_COOPERE
        { 0b00010001, {1.f, 1.f} }  // TRAHIT_TRAHIT
    };
};

std::pair<Resultat,Resultat> DilemnePrisonnier::duel(int coupJ1, int coupJ2)
{
    return ::duel(coupJ1, coupJ2, DilemnePrisonnier::matriceGains);
}
