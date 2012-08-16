#include "ParticleGenerator.h"

void ParticleGenerator::render(){
    return;
}

void ParticleGenerator::update(){
    for(int i = 0; i < intensity; i++){
        Actor::actors().push_back(new Particle());
    }
    return;
}
