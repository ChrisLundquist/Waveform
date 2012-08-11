#include <gtest/gtest.h>
#include "../src/Particle.h"

TEST(ParticleSpec,Construct) {
    Particle p = Particle();
}

TEST(ParticleSpec,Mass) {
    Particle p = Particle();
    p.get_mass();
}

TEST(ParticleSpec,Color) {
    Particle p = Particle();
    p.get_color();
}
