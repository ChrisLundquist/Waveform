#include <vector>
#include "../models/force.h"

struct ForceController {
    ForceController();
    std::vector<Force*> forces;
};
