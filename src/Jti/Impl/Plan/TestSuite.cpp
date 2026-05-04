#include "TestSuite.h"

#include "Jti/Impl/Logging/Log.hpp"

namespace jti {

TestSuite::TestSuite(const char* name) 
    : name(name) {}

const char* TestSuite::getName() const {
    return name;
}

unsigned TestSuite::totalTests() const {
    return static_cast<unsigned>(cases.size());
}

const TestCase* TestSuite::getTestCase(const char* caseName) const {
    for (auto& c : cases) {
        if (std::strcmp(c.getName(), caseName) == 0) {
            return &c;
        }
    }
    return nullptr;
}

TestCase* TestSuite::getTestCase(const char* caseName) {
    for (auto& c : cases) {
        if (std::strcmp(c.getName(), caseName) == 0) {
            return &c;
        }
    }
    return nullptr;
}

void TestSuite::addTestCase(const char* caseName, void(*caseImpl)()) {
    cases.emplace_back(caseName, caseImpl);
}

TestResult TestSuite::run() const {
    logTabbed("[TEST SUITE] %s tests are running\n", name);
    incrementLogTabs();

    TestResult result = runTests();
    unsigned total = totalTests();
    
    decrementLogTabs();
    setConsoleColour(result.getPassed() == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[TEST SUITE] %s tests passed %u/%u (%ums)\n", 
              name, result.getPassed(), total, result.getDurationMs());
    setConsoleColour(ConsoleColour::Default);

    return result;
}

TestResult TestSuite::runTests() const {
    TestResult result{};
    for (auto& c : cases) {
        result += c.run();
    }
    return result;
}

}