#include <gtest/gtest.h>
#include "../../src/controllers/actor_controller.h"
#include "../../src/models/particle_generator.h"

TEST(ParticleGenerator, Construct) {
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(generator.intensity, 0);
    EXPECT_EQ(generator.position[0], 0);
    EXPECT_EQ(generator.direction[0], 0);
}

TEST(ParticleGenerator, NewParticleVelocity) {
    ParticleGenerator generator = ParticleGenerator();
    generator.direction = glm::vec3(1,0,0);

    generator.intensity = 1;
    Particle p = *generator.generate();

    EXPECT_EQ(p.mass.velocity[0], generator.direction[0]);
}

TEST(ParticleGenerator, NewParticlePosition) {
    ParticleGenerator generator = ParticleGenerator();

    generator.intensity = 1;
    Particle p = *generator.generate();

    EXPECT_EQ(p.mass.position[0], generator.position[0]);
}
