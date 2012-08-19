#include "actor_controller.h"

std::vector<Actor*>* ActorController::actors_ = new std::vector<Actor*>();

std::vector<Actor*>& ActorController::actors() {
    return *actors_;
}
