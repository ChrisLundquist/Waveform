#include <vector>
#include "../models/particle_generator.h"

struct ParticleGeneratorController {
    ParticleGeneratorController();
    void generate();
    void apply_forces(std::vector<Force*> &forces);
    std::vector<ParticleGenerator*> generators;
};
