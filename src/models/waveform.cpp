#include <iostream>

#include "waveform.h"

Waveform::Waveform() {
    running_ = false;
}

void Waveform::update() {
    std::cout << "Updating" << std::endl;
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
