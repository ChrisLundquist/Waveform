#include <gtest/gtest.h>
#include "../../src/controllers/particle_generator_controller.h"

TEST(ParticleGeneratorController, Construct) {
    ParticleGeneratorController controller = ParticleGeneratorController();
    EXPECT_EQ(controller.generators.size(), 0);
}

