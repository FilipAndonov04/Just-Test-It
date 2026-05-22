#include "Register/TestRegister.h"

#include "Plan/TestPlan.h"

namespace jti {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}