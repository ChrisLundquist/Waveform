#include "Particle.h"

Particle::Particle() {
  mass = Mass();
  color = Color();
}

void Particle::render() {
    return;
}

void Particle::update() {
    mass.update();
    return;
}

