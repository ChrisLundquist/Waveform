#include "Actor.h"

std::vector<Actor*>* Actor::actors_ = new std::vector<Actor*>();

std::vector<Actor*>& Actor::actors() {
    return *actors_;
}
