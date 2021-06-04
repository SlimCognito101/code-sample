// author: Colin Seifer
// file: Window.cpp
// description: handles creation and destruction of window.

#include <stdio.h>
#include "Window.hpp"

// creates a GLFW window
Window::Window(int w, int h){
    // attempt to create window based on given width and height
    win = glfwCreateWindow(w, h, "Hire Me!", nullptr, nullptr);
    if(!win){
        perror("Window not created.\n");
    }
    // set GLFW context
    else{
        glfwMakeContextCurrent(win);
    }
    
    // set current width and height
    width = w;
    height = h;
}

// destroys created window
Window::~Window() 
{
    glfwDestroyWindow(win);
}