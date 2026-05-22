#include "Register/TestRegister.h"

#include "Impl/Plan/TestPlan.h"

namespace jti {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}