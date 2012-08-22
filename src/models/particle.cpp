#include "particle.h"

Particle::Particle() {
  color = Color();
  age = 0;
  position = glm::vec3(0);
  velocity = glm::vec3(0);
  acceleration = glm::vec3(0);
  mass = 0.0f;
}

void Particle::update() {
    age++;
    velocity += acceleration;
    position += velocity;
    return;
}

void Particle::apply(Force& force) {

}

