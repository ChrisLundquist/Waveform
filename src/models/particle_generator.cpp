#include "particle_generator.h"

ParticleGenerator::ParticleGenerator(){
    intensity = 0;
    direction = glm::vec3(0,0,0);
    position = glm::vec3(0,0,0);
}

Particle* ParticleGenerator::generate(){
    Particle* p = new Particle();
    p->mass.velocity = direction;
    p->mass.position = position;

    return p;
}
