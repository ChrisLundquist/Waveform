#include <gtest/gtest.h>
#include "../src/Particle.h"

TEST(Particle, Construct) {
    Particle p = Particle();
}

TEST(Particle, Render) {
    Particle p = Particle();
    p.render();
}

TEST(Particle, Update) {
    Particle p = Particle();
    p.update();
}

TEST(Particle,UpdatePosition) {
    Particle p = Particle();
    p.mass.velocity = glm::vec3(1,0,0);

    p.update();
    EXPECT_EQ(p.mass.position[0],1);
    p.update();
    EXPECT_EQ(p.mass.position[0],2);
}

TEST(Particle,UpdateAge) {
    Particle p = Particle();
    EXPECT_EQ(p.age, 0);

    p.update();

    EXPECT_EQ(p.age, 1);
}
