#include <gtest/gtest.h>
#include "../../src/controllers/force_controller.h"

TEST(ForceController, Construct) {
    ForceController controller = ForceController();

    EXPECT_EQ(controller.forces.size(), 0);
}
