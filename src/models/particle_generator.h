#include "particle.h"

struct ParticleGenerator {
    ParticleGenerator();
    Particle* generate();
    int intensity;
    glm::vec3 direction, position;
};
