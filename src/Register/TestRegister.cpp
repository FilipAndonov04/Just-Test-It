#include "Jti/Register/TestRegister.h"

#include "Jti/Impl/Plan/TestPlan.h"

namespace jti {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}