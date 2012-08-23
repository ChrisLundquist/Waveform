#include "particle_generator_controller.h"

ParticleGeneratorController::ParticleGeneratorController(){
    generators = std::vector<ParticleGenerator*>();
}

void ParticleGeneratorController::apply_forces( std::vector<Force*> &forces) {
    for(unsigned i = 0; i < generators.size(); i++) {
        ParticleGenerator generator = *generators[i];

        for( unsigned j = 0; j < generator.particles.size(); j++){
            Particle particle = *generator.particles[j];

            for(unsigned k = 0; k < forces.size(); k++){
                Force force  = *forces[k];
                particle.apply(force);
            }
        }
    }
}

void ParticleGeneratorController::generate() {
    for( unsigned i = 0; i < generators.size(); i++) {
        generators[i]->update();
    }
}
