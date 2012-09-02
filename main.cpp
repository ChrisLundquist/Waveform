#include <iostream>
#include "src/controllers/waveform.h"
#include "src/graphics.h"

static void init_graphics(int argc, char** argv) {
    glutInit(&argc,argv);
    glutCreateWindow("GLEW Test");

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    std::cout << "Status: Using GL " << glGetString(GL_VERSION) << std::endl;
}

int main(int argc, char** argv) {
    Waveform game = Waveform();

    init_graphics(argc, argv);

    game.start();
    while(game.running()){
        game.update();
        game.render();
        game.pause();
    }
    return 0;
}
