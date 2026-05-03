#include <Jti/Test.h>
#include <Jti/Asserts.h>
#include <Jti/EntryPoint.h>

#include "Box.h"

TEST_CASE(Box, EmptyOnConstruction) {
	Box box;

	ASSERT_TRUE(box.isEmpty(), "box should be empty on default contruction");
}