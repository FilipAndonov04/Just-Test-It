#pragma once

namespace jti {

class TestRegistration {
public:
	TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)());
};

}