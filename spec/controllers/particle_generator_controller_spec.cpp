#include <gtest/gtest.h>
#include "../../src/controllers/particle_generator_controller.h"
#include "../../src/controllers/actor_controller.h"
#include "../../src/models/particle_generator.h"

TEST(ParticleGeneratorController, Update){
    ParticleGeneratorController generator = ParticleGeneratorController();
    EXPECT_EQ(ActorController::actors().size(), 0);

    //generator.intensity = 1;
    generator.update();
    EXPECT_EQ(ActorController::actors().size(), 1);

    ActorController::actors().clear();
}

TEST(ParticleGeneratorController, UpdateRepeat){
    ParticleGeneratorController generator = ParticleGeneratorController();
    EXPECT_EQ(ActorController::actors().size(), 0);

    //generator.intensity = 1;
    generator.update();
    generator.update();
    EXPECT_EQ(ActorController::actors().size(), 2);

    ActorController::actors().clear();
}

TEST(ParticleGeneratorController, UpdateIntensity){
    ParticleGeneratorController generator = ParticleGeneratorController();
    EXPECT_EQ(ActorController::actors().size(), 0);

    //generator.intensity = 2;
    generator.update();
    EXPECT_EQ(ActorController::actors().size(), 2);

    ActorController::actors().clear();
}
