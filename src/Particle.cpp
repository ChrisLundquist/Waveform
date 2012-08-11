#include "Particle.h"

Particle::Particle() {
  mass = Mass();
  color = Color();
}

const Color& Particle::get_color() {
    return color;
}

const Mass& Particle::get_mass() {
    return mass;
}
