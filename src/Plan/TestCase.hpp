#pragma once

#include "Plan/TestResult.hpp"

namespace jti {

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