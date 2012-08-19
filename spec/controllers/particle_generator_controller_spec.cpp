#include <gtest/gtest.h>
#include "../../src/controllers/particle_generator_controller.h"
#include "../../src/models/particle_generator.h"

TEST(ParticleGeneratorController, Construct) {
    ParticleGeneratorController controller = ParticleGeneratorController();
    EXPECT_EQ(controller.actors().size(), 0);
}

