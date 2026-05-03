#pragma once

#include "Jti/Impl/Register/TestRegistration.h"
#include "Jti/Exception/TestFailedException.h"

namespace jti {

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

bool runAllTests();
bool runSuiteTests(const char* testSuite);
bool runTestCase(const char* testSuite, const char* testCase);

bool haveAllTestsPassed();

}