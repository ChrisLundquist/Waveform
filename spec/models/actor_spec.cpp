#include <gtest/gtest.h>
#include "../../src/models/Particle.h"

TEST(Actor,actors){
    Actor::actors();
}

TEST(Actor,Populate) {
    Particle *particle = new Particle();
    Actor::actors().push_back(particle);
    EXPECT_EQ(Actor::actors()[0], particle);
    EXPECT_EQ(Actor::actors().size(), 1);

    Actor::actors().clear();
}

TEST(Actor,Stress) {
    for(int i = 0; i < 1024; i++) {
        Particle *particle = new Particle();
        Actor::actors().push_back(particle);
        EXPECT_EQ(Actor::actors()[i], particle);
    }

    EXPECT_EQ(Actor::actors().size(), 1024);

    Actor::actors().clear();
}
