#include "Waveform.h"
Waveform::Waveform() {
    running_ = false;
}

void Waveform::update() {
    return;
}

bool Waveform::running() {
    return running_;
}

bool Waveform::pause() {
    return running_ = false;
}
