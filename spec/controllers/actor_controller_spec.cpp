#include <gtest/gtest.h>
#include "../../src/models/particle.h"
#include "../../src/controllers/actor_controller.h"

TEST(Actor,actors){
    ActorController::actors();
}

TEST(Actor,Populate) {
    Particle *particle = new Particle();
    ActorController::actors().push_back(particle);
    EXPECT_EQ(ActorController::actors()[0], particle);
    EXPECT_EQ(ActorController::actors().size(), 1);

    ActorController::actors().clear();
    delete particle;
}

TEST(Actor,Stress) {
    for(int i = 0; i < 1024; i++) {
        Particle *particle = new Particle();
        ActorController::actors().push_back(particle);
        EXPECT_EQ(ActorController::actors()[i], particle);
    }

    EXPECT_EQ(ActorController::actors().size(), 1024);

    ActorController::actors().clear();
}
