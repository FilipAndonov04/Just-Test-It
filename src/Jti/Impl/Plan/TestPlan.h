#pragma once

#include "Jti/Impl/Plan/TestSuite.h"

namespace jti {

class TestPlan {
public:
	unsigned totalTests() const;

	const TestSuite* getTestSuite(const char* suiteName) const;
	TestSuite* getTestSuite(const char* suiteName);
	const TestCase* getTestCase(const char* suiteName, const char* caseName) const;
	TestCase* getTestCase(const char* suiteName, const char* caseName);

	void addTestCase(const char* suiteName, const char* caseName, void(*caseImpl)());

	TestResult run() const;

private:
	TestResult runTests() const;

	std::vector<TestSuite> suites;
};

}