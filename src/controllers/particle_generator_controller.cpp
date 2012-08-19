#include "particle_generator_controller.h"

ParticleGeneratorController::ParticleGeneratorController(){
    generators = std::vector<ParticleGenerator*>();
}

void ParticleGeneratorController::update() {
    for( unsigned i = 0; i < generators.size(); i++) {
        ParticleGenerator generator = *generators[i];
        generator.update();
    }
}
