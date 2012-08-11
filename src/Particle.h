#include "Mass.h"
#include "Color.h"
#include "Actor.h"

class Particle : public Actor {
    Mass mass;
    Color color;

    public:
    Particle();
    virtual void render();
    virtual void update();
    const Mass& get_mass();
    const Color& get_color();
};
