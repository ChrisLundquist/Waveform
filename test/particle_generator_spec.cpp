#include <gtest/gtest.h>
#include "../src/ParticleGenerator.h"

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
