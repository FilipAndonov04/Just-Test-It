#include "TestRegister.h"

#include "Jti/Impl/Plan/TestPlan.h"

namespace Test {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}