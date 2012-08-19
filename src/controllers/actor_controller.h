#include <vector>
#include "../../src/models/actor.h"

struct ActorController {
    static std::vector<Actor*>& actors();

    private:
        static std::vector<Actor*>* actors_;
};
