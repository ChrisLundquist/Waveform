#include <vector>
#include "../models/particle_generator.h"

struct ParticleGeneratorController {
    ParticleGeneratorController();
    void update();
    std::vector<ParticleGenerator*> generators;
};
