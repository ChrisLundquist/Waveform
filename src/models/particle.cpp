#include "particle.h"

Particle::Particle() {
  color = glm::vec4(1,1,1,0);
  age = 0;
  position = glm::vec3(0,0,0);
  velocity = glm::vec3(0,0,0);
  acceleration = glm::vec3(0,0,0);
  mass = 0.0f;
}

void Particle::update() {
    age++;
    velocity += acceleration;
    position += velocity;
    return;
}

void Particle::apply(Force& force) {
    float length = glm::length(force.direction);

    if(length == 0)
        return;

    // Make sure we are adding a vector, not a scalar
    acceleration += force.direction * length / mass;
}

