#include "Jti/Test.h"

#include "Impl/Logging/Log.hpp"
#include "Impl/Plan/TestPlan.h"
#include "Register/TestRegister.h"

namespace jti {

static bool allTestsPassed = true;

bool runAllTests() {
	TestResult result = getTestRegister().run();
	log("\n");

	unsigned total = getTestRegister().totalTests();
	allTestsPassed &= result.getPassed() == total;
	return allTestsPassed;
}

bool runSuiteTests(const char* testSuite) {
	TestSuite* s = getTestRegister().getTestSuite(testSuite);
	if (!s) {
		setConsoleColour(ConsoleColour::Red);
		log("[ERROR] test suite %s does not exist\n\n", testSuite);
		setConsoleColour(ConsoleColour::Default);

		allTestsPassed = false;
		return false;
	}

	TestResult result = s->run();
	log("\n");

	unsigned total = s->totalTests();
	allTestsPassed &= result.getPassed() == total;
	return allTestsPassed;
}

bool runTestCase(const char* testSuite, const char* testCase) {
	TestCase* c = getTestRegister().getTestCase(testSuite, testCase);
	if (!c) {
		setConsoleColour(ConsoleColour::Red);
		log("[ERROR] test suite %s does not contain test case %s\n\n",
			testSuite, testCase);
		setConsoleColour(ConsoleColour::Default);

		allTestsPassed = false;
		return false;
	}

	TestResult result = c->run();
	allTestsPassed &= result.getPassed() != 0;
	log("\n");

	return allTestsPassed;
}

bool haveAllTestsPassed() {
	return allTestsPassed;
}

}