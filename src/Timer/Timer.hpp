#pragma once

#include <chrono>

namespace jti {

class Timer {
public:
	Timer();

	unsigned long long getTimePassedMs() const;

private:
	std::chrono::high_resolution_clock::time_point startTick;
};

}