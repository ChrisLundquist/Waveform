#include <gtest/gtest.h>
#include "../../src/models/ParticleGenerator.h"

TEST(ParticleGenerator, Construct) {
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(generator.intensity, 0);
    EXPECT_EQ(generator.position[0], 0);
    EXPECT_EQ(generator.direction[0], 0);
}

TEST(ParticleGenerator, Update){
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(Actor::actors().size(), 0);

    generator.intensity = 1;
    generator.update();
    EXPECT_EQ(Actor::actors().size(), 1);

    Actor::actors().clear();
}

TEST(ParticleGenerator, UpdateRepeat){
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(Actor::actors().size(), 0);

    generator.intensity = 1;
    generator.update();
    generator.update();
    EXPECT_EQ(Actor::actors().size(), 2);

    Actor::actors().clear();
}

TEST(ParticleGenerator, UpdateIntensity){
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(Actor::actors().size(), 0);

    generator.intensity = 2;
    generator.update();
    EXPECT_EQ(Actor::actors().size(), 2);

    Actor::actors().clear();
}

TEST(ParticleGenerator, NewParticleVelocity) {
    ParticleGenerator generator = ParticleGenerator();
    generator.direction = glm::vec3(1,0,0);
    EXPECT_EQ(Actor::actors().size(), 0);

    generator.intensity = 1;
    generator.update();
    EXPECT_EQ(Actor::actors().size(), 1);

    // Stupid syntax to get around needing an impossible constructor
    Particle p = *(Particle*) Actor::actors()[0];
    EXPECT_EQ(p.mass.velocity[0], generator.direction[0]);

    Actor::actors().clear();
}

TEST(ParticleGenerator, NewParticlePosition) {
    ParticleGenerator generator = ParticleGenerator();
    EXPECT_EQ(Actor::actors().size(), 0);

    generator.intensity = 1;
    generator.update();
    EXPECT_EQ(Actor::actors().size(), 1);

    // Stupid syntax to get around needing an impossible constructor
    Particle p = *(Particle*) Actor::actors()[0];
    EXPECT_EQ(p.mass.position[0], generator.position[0]);

    Actor::actors().clear();
}
