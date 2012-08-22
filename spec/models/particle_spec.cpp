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
    EXPECT_EQ(p.position.x, 1);
    p.update();
    EXPECT_EQ(p.position.x, 2);
}

TEST(Particle,UpdateAge) {
    Particle p = Particle();
    EXPECT_EQ(p.age, 0);

    p.update();

    EXPECT_EQ(p.age, 1);
}

TEST(Particle, ApplyZero) {
    Force f = Force();
    Particle p = Particle();
    p.apply(f);
    EXPECT_EQ(p.acceleration.x, 0);
}

TEST(Particle, ApplyOne) {
    Force f = Force();
    f.direction = glm::vec3(1, 0, 0);

    Particle p = Particle();
    p.position = glm::vec3(-1, 0, 0);
    p.mass = 1.0f;

    p.apply(f);
    EXPECT_EQ(p.acceleration.x, 1);
}

TEST(Particle, ApplyMass) {
    Force f = Force();
    f.direction = glm::vec3(1, 0, 0);

    Particle p = Particle();

    p.position = glm::vec3(-1, 0, 0);
    p.mass = 2.0f;

    p.apply(f);
    EXPECT_EQ(p.acceleration.x, 0.5f);
    EXPECT_EQ(p.acceleration.y, 0.0f);
    EXPECT_EQ(p.acceleration.z, 0.0f);
}

TEST(Particle, ApplyForces) {
    Force x = Force();
    Force y = Force();
    x.direction = glm::vec3(1, 0, 0);
    y.direction = glm::vec3(0, 1, 0);

    Particle p = Particle();
    p.mass = 1.0f;

    p.position = glm::vec3(-1, 0, 0);

    p.apply(x);
    EXPECT_EQ(p.acceleration.x, 1.0f);
    EXPECT_EQ(p.acceleration.y, 0.0f);

    p.apply(y);
    EXPECT_EQ(p.acceleration.x, 1.0f);
    EXPECT_EQ(p.acceleration.y, 1.0f);
}
