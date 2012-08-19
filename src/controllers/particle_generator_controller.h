#include <vector>
#include "../models/actor.h"

struct ParticleGeneratorController {
    ParticleGeneratorController();
    void update();
    const std::vector<Actor*>& actors();

     private:
         std::vector<Actor*> actors_;
};
