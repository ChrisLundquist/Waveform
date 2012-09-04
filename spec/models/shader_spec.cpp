#include <gtest/gtest.h>
#include "../../src/models/shader.h"

static void init() {
    int argc = 0;
    char** argv = NULL;
    glewExperimental = GL_TRUE;
    glutInit(&argc, argv);
    glutCreateWindow("GLEW Test");
    glewInit();
}

TEST(Shader,Construct) {
    init();
    Shader minimal = Shader("shaders/minimal.vert", "shaders/minimal.frag");
    EXPECT_NE(minimal.id(), 0);
}

