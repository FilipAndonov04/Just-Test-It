#pragma once

#include <cstdio>

namespace jti {

template <typename... Ts>
inline void log(const char* fmt, const Ts&... ts) {
	std::printf(fmt, ts...);
}

unsigned getLogTabs();
void setLogTabs(unsigned tabs);
void incrementLogTabs();
void decrementLogTabs();

template <typename... Ts>
inline void logTabbed(const char* fmt, const Ts&... ts) {
	for (unsigned i = 0; i < getLogTabs(); i++) {
		log("\t");
	}
	log(fmt, ts...);
}

enum class ConsoleColour {
	Default,
	Green,
	Red
};

void setConsoleColour(ConsoleColour colour);
void resetConsoleColour();

}