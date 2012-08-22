#include <gtest/gtest.h>
#include "../../src/models/particle.h"

TEST(Particle, Construct) {
    Particle p = Particle();
}

TEST(Particle, Update) {
    Particle p = Particle();
    p.update();
}

TEST(Particle,UpdatePosition) {
    Particle p = Particle();
    p.velocity = glm::vec3(1, 0, 0);

    p.update();
    EXPECT_EQ(p.position[0], 1);
    p.update();
    EXPECT_EQ(p.position[0], 2);
}

TEST(Particle,UpdateAge) {
    Particle p = Particle();
    EXPECT_EQ(p.age, 0);

    p.update();

    EXPECT_EQ(p.age, 1);
}

TEST(Force, ApplyZero) {
    Force f = Force();
    Particle p = Particle();
    p.apply(f);
    EXPECT_EQ(p.acceleration[0], 0);
}

TEST(Force, Apply) {
    Force f = Force();
    f.direction = glm::vec3(1, 0, 0);
    Particle p = Particle();
    p.position = glm::vec3(-1, 0, 0);
    p.mass = 1.0f;
    p.apply(f);
    EXPECT_EQ(p.acceleration[0], 1);
}
