#pragma once
#include "Impl/Plan/TestSuite.h"

namespace Test {

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