#include <iostream>
#include "waveform.h"

Waveform::Waveform() {
    running_ = false;
    forces_controller = ForceController();
    particles_controller = ParticleGeneratorController();
}

void Waveform::update() {
    particles_controller.generate();
    apply_forces();
}

bool Waveform::running() {
    return running_;
}

bool Waveform::pause() {
    return running_ = false;
}

bool Waveform::start() {
    return running_ = true;
}

void Waveform::apply_forces() {
    particles_controller.apply_forces(forces_controller.forces);
}
