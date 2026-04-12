#pragma once
#include "Impl/Plan/TestCase.h"

#include <vector>

namespace Test {

class TestSuite {
public:
	explicit TestSuite(const char* name);

	const char* getName() const;
	unsigned totalTests() const;

	const TestCase* getTestCase(const char* caseName) const;
	TestCase* getTestCase(const char* caseName);

	void addTestCase(const char* caseName, void(*caseImpl)());
	
	TestResult run() const;

private:
	TestResult runTests() const;

	const char* name;
	std::vector<TestCase> cases;
};

}