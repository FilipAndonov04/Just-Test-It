#pragma once
#include "Impl/Plan/TestResult.h"

namespace Test {

class TestCase {
public:
	TestCase(const char* name, void (*impl)());

	const char* getName() const;

	TestResult run() const;

private:
	const char* name;
	void (*impl)();
};

}