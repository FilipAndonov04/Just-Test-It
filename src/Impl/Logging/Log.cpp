#include "Impl/Logging/Log.hpp"

namespace jti {

static unsigned logTabs = 0;

unsigned getLogTabs() {
	return logTabs;
}

void setLogTabs(unsigned tabs) {
	logTabs = tabs;
}

void incrementLogTabs() {
	logTabs++;
}

void decrementLogTabs() {
	if (logTabs != 0) {
		logTabs--;
	}
}

void setConsoleColour(ConsoleColour colour) {
	constexpr const char* ANSI_COLOUR_DEFAULT = "\x1B[39m";
	constexpr const char* ANSI_COLOUR_GREEN = "\x1B[32m";
	constexpr const char* ANSI_COLOUR_RED = "\x1B[31m";

	const char* colourCode;
	switch (colour) {
	case ConsoleColour::Green:
		colourCode = ANSI_COLOUR_GREEN;
		break;
	case ConsoleColour::Red:
		colourCode = ANSI_COLOUR_RED;
		break;
	default:
		colourCode = ANSI_COLOUR_DEFAULT;
		break;
	}

	log(colourCode);
}

void resetConsoleColour() {
	setConsoleColour(ConsoleColour::Default);
}

}