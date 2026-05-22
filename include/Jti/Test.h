#pragma once

#include "Jti/Register/TestRegistration.h"
#include "Jti/Exception/TestFailedException.h"

namespace jti {

/*
 * Run all tests.
 * 
 * @return True if all run tests passed, false otherwise.
 */
bool runAllTests();

/*
 * Run the tests in a suite.
 * 
 * @param testSuite - The suite's name.
 * @return True if all run tests passed, false otherwise.
 */
bool runSuiteTests(const char* testSuite);

/*
 * Run a test case.
 *
 * @param testSuite - The suite's name.
 * @param testCase - The case's name.
 * @return True if the test passed, false otherwise.
 */
bool runTestCase(const char* testSuite, const char* testCase);

/*
 * Check if all run tests up to this moment have passed.
 *
 * @return True if all run tests have passed, false otherwise.
 */
bool haveAllTestsPassed();

#define TEST_CASE(suite, name) \
	void test##suite##name(); \
	void test##suite##name##_structure() { \
		try { \
			test##suite##name(); \
		} catch (const jti::TestFailedException&) { \
			throw; \
		} catch (const std::exception& e) { \
			throw jti::TestFailedException(std::string("an unexpected exception occurred: ") + e.what(), \
										   __FILE__, __LINE__); \
		} catch (...) { \
			throw jti::TestFailedException("an unexpected error occurred", __FILE__, __LINE__); \
		} \
	} \
	static jti::TestRegistration testRegistration##suite##name(#suite, #name, &test##suite##name##_structure); \
	void test##suite##name()

#define TEST_MAIN() \
	void main_impl(); \
	int main() { \
		main_impl(); \
		return jti::haveAllTestsPassed() ? EXIT_SUCCESS : EXIT_FAILURE; \
	} \
	void main_impl()

}