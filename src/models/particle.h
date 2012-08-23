#include "actor.h"
#include "force.h"

struct Particle : public Actor {
    Particle();
    virtual void update();
    void apply(Force& force);
    int age;
    float mass;
    glm::vec3 position, velocity, acceleration;
    glm::vec4 color;
};
