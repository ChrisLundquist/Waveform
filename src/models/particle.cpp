#include "Particle.h"

Particle::Particle() {
  mass = Mass();
  color = Color();
  age = 0;
}

void Particle::update() {
    age++;
    mass.update();
    return;
}

