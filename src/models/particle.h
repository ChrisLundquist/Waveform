#include "color.h"
#include "actor.h"
#include "force.h"

struct Particle : public Actor {
    Particle();
    virtual void update();
    void apply(Force& force);
    Color color;
    int age;
    float mass;
    glm::vec3 position, velocity, acceleration;
};
