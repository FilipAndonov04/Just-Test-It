#include "Jti/Register/TestRegistration.h"

#include "Register/TestRegister.h"
#include "Plan/TestPlan.h"

namespace jti {

TestRegistration::TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    getTestRegister().addTestCase(suiteName, caseName, caseImpl);
}

}