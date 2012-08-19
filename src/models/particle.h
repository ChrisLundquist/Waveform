#include "mass.h"
#include "color.h"
#include "actor.h"

struct Particle : public Actor {
    Particle();
    virtual void update();
    Mass mass;
    Color color;
    int age;
};
