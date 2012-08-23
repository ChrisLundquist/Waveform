#include <vector>
#include "particle_generator_controller.h"
#include "force_controller.h"

class Waveform {
    bool running_;
    ForceController forces_controller;
    ParticleGeneratorController particles_controller;
    void apply_forces();
  public:
    Waveform();
    void update();
    bool running();
    bool pause();
    bool start();
};
