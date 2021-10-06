// author: Colin Seifer
// file: Window.cpp
// description: handles creation and destruction of window.

#include <stdio.h>
#include "Window.hpp"
#include "image_loader.hpp"

// creates a GLFW window
Window::Window(int w, int h){
    // attempt to create window based on given width and height
    win = glfwCreateWindow(w, h, "Metroid: Zebes Invasion Order", nullptr, nullptr);
    if(!win){
        perror("Window not created.\n");
    }
    // set GLFW context
    else{
        glfwMakeContextCurrent(win);
        // set window icon and load image
        GLFWimage image[1];
        image[0].pixels = Image_Loader::Load_Image("../data/icon.png", &image[0].width, &image[0].height, true);
        glfwSetWindowIcon(win, 1, image);

        Image_Loader::Free_Image(image->pixels);
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