#include "TestRegistration.h"

#include "Jti/Impl/Register/TestRegister.h"
#include "Jti/Impl/Plan/TestPlan.h"

namespace Test {

TestRegistration::TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    getTestRegister().addTestCase(suiteName, caseName, caseImpl);
}

}