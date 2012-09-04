#include <GL/glew.h>
#ifdef __APPLE__
#  include <OpenGL/OpenGL.h>
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <OpenGL/CGLTypes.h>
#  include <OpenGL/CGLCurrent.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif
