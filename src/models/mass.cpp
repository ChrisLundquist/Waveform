#include "mass.h"

Mass::Mass() {
    mass = 0.0f;
    position = glm::vec3(0.0f);
    velocity = glm::vec3(0.0f);
    acceleration = glm::vec3(0.0f);
}


void Mass::update() {
    velocity += acceleration;
    position += velocity;
}
