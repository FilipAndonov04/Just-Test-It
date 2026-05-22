#include "Jti/Register/TestRegistration.hpp"

#include "Register/TestRegister.hpp"
#include "Plan/TestPlan.hpp"

namespace jti {

TestRegistration::TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    getTestRegister().addTestCase(suiteName, caseName, caseImpl);
}

}