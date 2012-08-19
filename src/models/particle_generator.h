#include <vector>
#include "particle.h"

struct ParticleGenerator {
    ParticleGenerator();
    ~ParticleGenerator();
    Particle* generate();
    void update();
    int intensity;
    glm::vec3 direction, position;
    std::vector<Particle*> particles;
};
