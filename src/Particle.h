#include "Mass.h"
#include "Color.h"

class Particle {
    Mass mass;
    Color color;

    public:
        Particle();
        const Mass& get_mass();
        const Color& get_color();
};
