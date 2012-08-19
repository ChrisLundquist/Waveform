#include "particle_generator_controller.h"
#include "../models/particle_generator.h"


ParticleGeneratorController::ParticleGeneratorController(){
    actors_ = std::vector<Actor*>();
}

const std::vector<Actor*>& ParticleGeneratorController::actors() {
    return actors_;
}

void ParticleGeneratorController::update() {
    for( unsigned i = 0; i < actors().size(); i++) {
        ParticleGenerator generator = *(ParticleGenerator*) actors()[i];
        generator.update();
    }
}
