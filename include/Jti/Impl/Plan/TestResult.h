#pragma once

namespace jti {

class TestResult {
public:
    TestResult() = default;
    TestResult(unsigned passed, unsigned long long durationMs);

    TestResult& operator+=(const TestResult& rhs);

    unsigned getPassed() const;
    unsigned long long getDurationMs() const;

private:
    unsigned passed = 0;
    unsigned long long durationMs = 0;
};

}