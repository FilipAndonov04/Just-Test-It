#pragma once

#include "Jti/Impl/Plan/TestResult.h"

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