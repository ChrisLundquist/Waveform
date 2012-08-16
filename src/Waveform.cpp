#include <iostream>

#include "Waveform.h"
#include "Actor.h"

Waveform::Waveform() {
    running_ = false;
}

void Waveform::update() {
    std::cout << "Updating" << std::endl;

    std::vector<Actor*> actors = Actor::actors();

    for( unsigned i = 0; i < actors.size(); i++){
        Actor* actor = actors[i];
        actor->update();
    }
    return;
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
