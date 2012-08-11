#include "Particle.h"

Particle::Particle() {
  mass = Mass();
  color = Color();
}

void Particle::render() {
    return;
}

void Particle::update() {
    return;
}

const Color& Particle::get_color() {
    return color;
}

const Mass& Particle::get_mass() {
    return mass;
}
