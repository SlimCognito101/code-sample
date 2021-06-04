// author: Colin Seifer
// file: driver.cpp
// description: initializes GL system and runs main loop.

#include <stdio.h>
#include "Window.hpp"

int main(){
    // attempt to initlalize GLFW
    if(!glfwInit()){
        perror("Unable to initialize GLFW!\n");
        return -1;
    }

    // adjust for OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // for MacOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    Window win = Window();
    // attempt to initialize OpenGL
    glewExperimental = true;
    if(glewInit() != GLEW_OK){
        perror("Unable to initialize GLEW.\n");
        return -1;
    }

    // main loop. Render and check for events.
    while(!glfwWindowShouldClose(win.win)){
        glfwPollEvents();
    }

    glfwTerminate();
}