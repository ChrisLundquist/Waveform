#include <vector>
#include "../models/force.h"

struct ForceController {
    ForceController();
    void render();
    std::vector<Force*> forces;
};
