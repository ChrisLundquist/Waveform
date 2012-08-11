#include <gtest/gtest.h>
#include "../src/Particle.h"

TEST(Particle,Construct) {
    Particle p = Particle();
}

TEST(Particle,Mass) {
    Particle p = Particle();
    p.get_mass();
}

TEST(Particle,Color) {
    Particle p = Particle();
    p.get_color();
}

TEST(Particle,Render) {
    Particle p = Particle();
    p.render();
}

TEST(Particle,Update) {
    Particle p = Particle();
    p.update();
}
