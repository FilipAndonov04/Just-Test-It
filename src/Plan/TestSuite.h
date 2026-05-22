#pragma once

#include <vector>

#include "Plan/TestCase.h"

namespace jti {

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