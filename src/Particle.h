#include "Mass.h"
#include "Color.h"
#include "Actor.h"

struct Particle : public Actor {
    Particle();
    virtual void render();
    virtual void update();
    Mass mass;
    Color color;
};
