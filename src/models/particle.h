#ifndef PARTICLE_H
#define PARTICLE_H

#include "force.h"

struct Particle {
    Particle();
    virtual void update();
    void apply(Force& force);
    int age;
    float mass;
    glm::vec3 position, velocity, acceleration;
    glm::vec4 color;
};
#endif
