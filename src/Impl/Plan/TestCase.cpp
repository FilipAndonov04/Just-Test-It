#include "Jti/Impl/Plan/TestCase.h"

#include "Jti/Impl/Logging/Log.hpp"
#include "Jti/Impl/Timer/Timer.h"
#include "Jti/Exception/TestFailedException.h"

namespace jti {

TestCase::TestCase(const char* name, void (*impl)())
    : name(name), impl(impl) {}

const char* TestCase::getName() const {
    return name;
}

TestResult TestCase::run() const {
    Timer timer;
    try {
        impl();
        auto duration = timer.getTimePassedMs();

        setConsoleColour(ConsoleColour::Green);
        logTabbed("[TEST CASE] %s passed (%ums)\n", 
                  name, duration);
        resetConsoleColour();

        return TestResult{true, duration};
    } catch (const TestFailedException& e) {
        auto duration = timer.getTimePassedMs();

        setConsoleColour(ConsoleColour::Red);
        logTabbed("[TEST CASE] %s (%s:%i) failed (%ums): %s\n", 
                  name, e.getFile(), e.getLine(), duration, e.what());
        resetConsoleColour();

        return TestResult{false, duration};
    }
}

}