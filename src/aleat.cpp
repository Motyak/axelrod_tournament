#include <aleat.h>

#include <random>

std::random_device randomDevice;

bool aleat(float probaTrue)
{
    return (randomDevice() % 1000000) < (probaTrue * 1000000);
}

int equiAleat(int from, int to)
{
    return randomDevice() % (to + 1) + from;
}
