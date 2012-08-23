#include <gtest/gtest.h>
#include "../../src/controllers/particle_generator_controller.h"

TEST(ParticleGeneratorController, Construct) {
    ParticleGeneratorController controller = ParticleGeneratorController();
    EXPECT_EQ(controller.generators.size(), 0);
}

TEST(ParticleGeneratorController, Generate) {
    ParticleGeneratorController controller = ParticleGeneratorController();
    ParticleGenerator generator = ParticleGenerator();
    generator.intensity = 1;

    EXPECT_EQ(controller.generators.size(), 0);
    controller.generators.push_back(&generator);

    EXPECT_EQ(controller.generators.size(), 1);

    controller.generate();

    EXPECT_EQ(generator.particles.size(), 1);
}
