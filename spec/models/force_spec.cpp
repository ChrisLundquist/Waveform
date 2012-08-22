#include <gtest/gtest.h>
#include "../../src/models/force.h"

TEST(Force, Construct) {
    Force f = Force();
    EXPECT_EQ(f.position[0], 0);
    EXPECT_EQ(f.direction[0], 0);
}
