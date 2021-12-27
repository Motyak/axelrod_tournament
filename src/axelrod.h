
#ifndef AXELROD_H
#define AXELROD_H

#include <utility>
#include <array>

enum Coup
{
    COOPERERATION,
    TRAHISON
};

enum Resultat
{
    COOP_COOP,
    TRAHI_TRAHI,
    COOP_TRAHI,
    TRAHI_COOP
};

using Score = double;
using MatriceDesGains = std::array<std::pair<Score,Score>,4>;

#endif