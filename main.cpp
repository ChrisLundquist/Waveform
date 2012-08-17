#include <iostream>
#include "src/graphics.h"
#include "src/models/Waveform.h"

int main(int argc, char** argv) {
    Waveform game = Waveform();

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

    game.start();
    while(game.running()){
        game.update();
    }
    return 0;
}
