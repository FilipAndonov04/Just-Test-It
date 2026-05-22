#include "Jti/Register/TestRegistration.h"

#include "Jti/Register/TestRegister.h"
#include "Jti/Impl/Plan/TestPlan.h"

namespace jti {

TestRegistration::TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    getTestRegister().addTestCase(suiteName, caseName, caseImpl);
}

}