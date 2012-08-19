#include "particle_generator.h"

ParticleGenerator::ParticleGenerator(){
    intensity = 0;
    direction = glm::vec3(0,0,0);
    position = glm::vec3(0,0,0);
}

void ParticleGenerator::render(){
    return;
}

void ParticleGenerator::update(){
    for(int i = 0; i < intensity; i++){
        Particle* p = new Particle();
        p->mass.velocity = direction;
        p->mass.position = position;
        Actor::actors().push_back(p);
    }
    return;
}
