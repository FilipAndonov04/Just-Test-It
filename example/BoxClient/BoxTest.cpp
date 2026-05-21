#include <Jti/Test.h>
#include <Jti/Assert.h>
#include <Jti/EntryPoint.h>

#include "Box.h"

TEST_CASE(Box, EmptyOnDefaultConstruction) {
	Box box;

	ASSERT_TRUE(box.isEmpty(), "box should be empty on default contruction");
}

TEST_CASE(Box, EmptyOnConstructionWithEmptyString) {
	Box box("");

	ASSERT_TRUE(box.isEmpty(), "box should be empty on contruction with empty string");
}

TEST_CASE(Box, NotEmptyOnConstructionWithNonemptyString) {
	Box box("cat");

	ASSERT_FALSE(box.isEmpty(), "box should not be empty on contruction with nonempty string");
}