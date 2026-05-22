#include "Register/TestRegister.hpp"

#include "Plan/TestPlan.hpp"

namespace jti {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}