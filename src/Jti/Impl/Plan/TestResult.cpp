#include "TestResult.h"

namespace jti {

TestResult::TestResult(unsigned passed, unsigned long long durationMs) 
    : passed(passed), durationMs(durationMs) {}

TestResult& TestResult::operator+=(const TestResult& rhs) {
    passed += rhs.passed;
    durationMs += rhs.durationMs;
    return *this;
}

unsigned TestResult::getPassed() const {
    return passed;
}

unsigned long long TestResult::getDurationMs() const {
    return durationMs;
}

}