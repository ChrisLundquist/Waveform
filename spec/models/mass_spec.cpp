#include <gtest/gtest.h>
#include "../../src/models/Mass.h"

TEST(Mass,Construct) {
    Mass m = Mass();
    EXPECT_EQ(m.position[0], 0);
    EXPECT_EQ(m.velocity[0], 0);
    EXPECT_EQ(m.acceleration[0], 0);
    EXPECT_EQ(m.mass, 0);
}

TEST(Mass,UpdateVelocity) {
    Mass mass = Mass();
    mass.velocity = glm::vec3(1,0,0);
    mass.update();
    EXPECT_EQ(mass.position[0], mass.velocity[0]);
}

TEST(Mass,UpdateAcceleration) {
    Mass mass = Mass();

    mass.acceleration = glm::vec3(1,0,0);
    mass.update();
    EXPECT_EQ(mass.velocity[0], mass.acceleration[0]);
    EXPECT_EQ(mass.position[0], mass.acceleration[0]);
}

TEST(Mass,Movement) {
    Mass mass = Mass();

    mass.acceleration = glm::vec3(2,0,0);

    mass.update();
    mass.update();

    EXPECT_EQ(mass.position[0],6);
}
