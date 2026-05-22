#include "Jti/Impl/Timer/Timer.h"

namespace jti {

Timer::Timer() 
    : startTick(std::chrono::steady_clock::now()) {}

unsigned long long Timer::getTimePassedMs() const {
    auto stopTick = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stopTick - startTick).count();
}

}