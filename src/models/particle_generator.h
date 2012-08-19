#include "Particle.h"

struct ParticleGenerator : Actor  {
    ParticleGenerator();
    void render();
    void update();
    int intensity;
    glm::vec3 direction, position;
};
