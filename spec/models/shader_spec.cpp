#include <gtest/gtest.h>
#include "../../src/models/shader.h"

static CGLContextObj context;

static void init() {
    int argc = 0;
    char** argv = NULL;

    CGLPixelFormatAttribute attributes[4] = {
        kCGLPFAAccelerated,   // no software rendering
        kCGLPFAOpenGLProfile, // core profile with the version stated below
        (CGLPixelFormatAttribute) kCGLOGLPVersion_3_2_Core,
        (CGLPixelFormatAttribute) 0
    };

    CGLPixelFormatObj pix;
    CGLError errorCode;
    GLint num; // stores the number of possible pixel formats
    errorCode = CGLChoosePixelFormat( attributes, &pix, &num );
    // add error checking here
    errorCode = CGLCreateContext( pix, NULL, &context); // second parameter can be another context for object sharing
    // add error checking here
    CGLDestroyPixelFormat( pix );

    errorCode = CGLSetCurrentContext( context );
    glutInit(&argc, argv);
    glewInit();
}

static void clean() {
    CGLSetCurrentContext( NULL );
    CGLDestroyContext( context );
}

TEST(Shader,Construct) {
    init();
    Shader minimal = Shader("shaders/minimal.vert", "shaders/minimal.frag");
    EXPECT_NE(minimal.id(), 0);
    clean();
}

