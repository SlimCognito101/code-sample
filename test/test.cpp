// author: Colin Seifer
// file: test.cpp
// description: tests functionality of app using Catch2 test framework.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdio.h>
#include "../src/Window.hpp"
#include "../src/Shaders.hpp"

TEST_CASE( "window size", "test size of default window and custom window" ){
    // attempt to initlalize GLFW
    glfwInit();

    // adjust for OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // for MacOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // test window sizes in default case and custom size.
    Window win = Window();
    REQUIRE(win.width == 720 && win.height == 480);
    Window win2 = Window(400, 401);
    REQUIRE(win.width == 400 && win.height == 401);

    glfwTerminate();
}

TEST_CASE( "shaders", "test that shaders return false if given bad data"){
    // attempt to initlalize GLFW
    glfwInit();

    // adjust for OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // for MacOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    Window win = Window();

    // attempt to initialize OpenGL
    glewExperimental = true;
    glewInit();

    // TODO: create object to load shaders.

    glfwTerminate();
}