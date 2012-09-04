#include "shader.h"
#include <string>
#include <fstream>
#include <iostream>

#define BUFFER_SIZE 512

/**
    text_file_read loads in a standard text file from a given filename and
    then returns it as a string.
*/
static std::string text_file_read(const char *fileName) {
    std::string fileString = std::string(); // A string for storing the file contents
    std::string line = std::string(); // A string for holding the current line

    std::ifstream file(fileName); // Open an input stream with the selected file
    if (file.is_open()) { // If the file opened successfully
        while (!file.eof()) { // While we are not at the end of the file
            getline(file, line); // Get the current line
            fileString.append(line); // Append the line to our file string
            fileString.append("\n"); // Append a new line character
        }
        file.close(); // Close the file
    }

    return fileString; // Return our string
}

/**
    Given a shader and the filename associated with it, validate_shader will
    then get information from OpenGl on whether or not the shader was compiled successfully
    and if it wasn't, it will output the file with the problem, as well as the problem.
*/
static void validate_shader(GLuint shader, const char* file = 0) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;

    glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer); // Ask OpenGL to give us the log associated with the shader
    if (length > 0) // If we have any information to display
        std::cerr << "Shader " << shader << " (" << (file ? file : "") << ") compile error: " << buffer << std::endl; // Output the information
}

/**
    Given a shader program, validate_program will request from OpenGL, any information
    related to the validation or linking of the program with it's attached shaders. It will
    then output any issues that have occurred.
*/
static void validate_program(GLuint program) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;
    GLint status = 0;

    glGetProgramInfoLog(program, BUFFER_SIZE, &length, buffer); // Ask OpenGL to give us the log associated with the program
    if (length > 0) // If we have any information to display
        std::cerr << "Program " << program << " link error: " << buffer << std::endl; // Output the information

    glValidateProgram(program); // Get OpenGL to try validating the program
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status); // Find out if the shader program validated correctly
    if (status == GL_FALSE) // If there was a problem validating
        std::cerr << "Error validating shader " << program << std::endl; // Output which program had the error
}

/**
    Default constructor for the Shader class, at the moment it does nothing
*/
Shader::Shader() {

}

/**
    Constructor for a Shader object which creates a GLSL shader based on a given
    vertex and fragment shader file.
*/
Shader::Shader(const char *vsFile, const char *fsFile) {
    inited = false; // Declare we have not initialized the shader yet

    init(vsFile, fsFile); // Initialize the shader
}
/**
    init will take a vertex shader file and fragment shader file, and then attempt to create a valid
    shader program from these. It will also check for any shader compilation issues along the way.
*/
void Shader::init(const char *vsFile, const char *fsFile) {
    if (inited) // If we have already initialized the shader
        return;

    inited = true; // Mark that we have initialized the shader

    shader_vp = glCreateShader(GL_VERTEX_SHADER); // Create a vertex shader
    shader_fp = glCreateShader(GL_FRAGMENT_SHADER); // Create a fragment shader

    std::string vsText = text_file_read(vsFile); // Read in the vertex shader
    std::string fsText = text_file_read(fsFile); // Read in the fragment shader

    const char *vertexText = vsText.c_str();
    const char *fragmentText = fsText.c_str();

    if (vertexText == NULL) {
        std::cout << "vertex shader shader file not found." << std::endl; // Output the error
        return;
    }

    if (fragmentText == NULL) {
        std::cout << "fragment shader file not found." << std::endl; // Output the error
        return;
    }

    glShaderSource(shader_vp, 1, &vertexText, 0); // Set the source for the vertex shader to the loaded text
    glCompileShader(shader_vp); // Compile the vertex shader
    validate_shader(shader_vp, vsFile); // Validate the vertex shader

    glShaderSource(shader_fp, 1, &fragmentText, 0); // Set the source for the fragment shader to the loaded text
    glCompileShader(shader_fp); // Compile the fragment shader
    validate_shader(shader_fp, fsFile); // Validate the fragment shader

    shader_id = glCreateProgram(); // Create a GLSL program
    glAttachShader(shader_id, shader_vp); // Attach a vertex shader to the program
    glAttachShader(shader_id, shader_fp); // Attach the fragment shader to the program

    glBindAttribLocation(shader_id, 0, "in_Position"); // Bind a constant attribute location for positions of vertices
    glBindAttribLocation(shader_id, 1, "in_Color"); // Bind another constant attribute location, this time for color

    glLinkProgram(shader_id); // Link the vertex and fragment shaders in the program
    validate_program(shader_id); // Validate the shader program
}

/**
    Deconstructor for the Shader object which cleans up by detaching the shaders, deleting them
    and finally deleting the GLSL program.
*/
Shader::~Shader() {
    glDetachShader(shader_id, shader_fp); // Detach the fragment shader
    glDetachShader(shader_id, shader_vp); // Detach the vertex shader

    glDeleteShader(shader_fp); // Delete the fragment shader
    glDeleteShader(shader_vp); // Delete the vertex shader
    glDeleteProgram(shader_id); // Delete the shader program
}

/**
    id returns the integer value associated with the shader program
*/
unsigned int Shader::id() {
    return shader_id; // Return the shaders identifier
}

/**
    bind attaches the shader program for use by OpenGL
*/
void Shader::bind() {
    glUseProgram(shader_id);
}

/**
    unbind detaches the shader program from OpenGL
*/
void Shader::unbind() {
    glUseProgram(0);
}
