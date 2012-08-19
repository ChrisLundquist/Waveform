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
    Particle* p = generator.generate();

    EXPECT_EQ(p->mass.velocity[0], generator.direction[0]);
    delete p;
}

TEST(ParticleGenerator, NewParticlePosition) {
    ParticleGenerator generator = ParticleGenerator();

    generator.intensity = 1;
    Particle* p = generator.generate();

    EXPECT_EQ(p->mass.position[0], generator.position[0]);
    delete p;
}

TEST(ParticleGenerator, Update){
    ParticleGenerator generator = ParticleGenerator();

    generator.intensity = 1;
    generator.update();

    EXPECT_EQ(generator.particles.size(), 1);
}

TEST(ParticleGenerator, UpdateRepeat){
    ParticleGenerator generator = ParticleGenerator();

    generator.intensity = 1;
    generator.update();
    generator.update();

    EXPECT_EQ(generator.particles.size(), 2);
}

TEST(ParticleGenerator, UpdateIntensity){
    ParticleGenerator generator = ParticleGenerator();

    generator.intensity = 2;
    generator.update();
    EXPECT_EQ(generator.particles.size(), 2);
}
