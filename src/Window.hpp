// author: Colin Seifer
// file: Window.hpp
// description: holds information necessary for creating window.

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window{
public:
    struct GLFWwindow* win; // GLFW window
    double width, height;   // window dimensions

    Window(int w = 1280, int h = 720);
    ~Window();
};

#endif