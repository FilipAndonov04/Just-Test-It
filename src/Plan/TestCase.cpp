#include "Plan/TestCase.hpp"

#include "Logging/Log.hpp"
#include "Timer/Timer.hpp"
#include "Jti/Exception/TestFailedException.hpp"

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