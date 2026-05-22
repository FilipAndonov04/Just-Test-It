#include "Jti/Impl/Plan/TestPlan.h"

#include "Jti/Impl/Logging/Log.hpp"

namespace jti {

void TestPlan::addTestCase(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    for (auto& suite : suites) {
        if (std::strcmp(suite.getName(), suiteName) == 0) {
            suite.addTestCase(caseName, caseImpl);
            return;
        }
    }

    suites.emplace_back(suiteName);
    suites.back().addTestCase(caseName, caseImpl);
}

const TestSuite* TestPlan::getTestSuite(const char* suiteName) const {
    for (auto& suite : suites) {
        if (std::strcmp(suite.getName(), suiteName) == 0) {
            return &suite;
        }
    }
    return nullptr;
}

TestSuite* TestPlan::getTestSuite(const char* suiteName) {
    for (auto& suite : suites) {
        if (std::strcmp(suite.getName(), suiteName) == 0) {
            return &suite;
        }
    }
    return nullptr;
}

const TestCase* TestPlan::getTestCase(const char* suiteName, const char* caseName) const {
    const TestSuite* suite = getTestSuite(suiteName);
    if (!suite) {
        return nullptr;
    }

    return suite->getTestCase(caseName);
}

TestCase* TestPlan::getTestCase(const char* suiteName, const char* caseName) {
    TestSuite* suite = getTestSuite(suiteName);
    if (!suite) {
        return nullptr;
    }

    return suite->getTestCase(caseName);
}

unsigned TestPlan::totalTests() const {
    unsigned total = 0;
    for (const auto& suite : suites) {
        total += suite.totalTests();
    }
    return total;
}

TestResult TestPlan::run() const {
    logTabbed("[ALL TESTS] tests are running\n");
    incrementLogTabs();

    TestResult result = runTests();
    unsigned total = totalTests();

    decrementLogTabs();
    setConsoleColour(result.getPassed() == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[ALL TESTS] tests passed %u/%u (%ums)\n", 
              result.getPassed(), total, result.getDurationMs());
    setConsoleColour(ConsoleColour::Default);

    return result;
}

TestResult TestPlan::runTests() const {
    TestResult result{};
    for (const auto& suite : suites) {
        result += suite.run();
    }
    return result;
}

}