// author: Colin Seifer
// file: Scene.hpp
// description: holds current information about the scene.

#ifndef SCENE_HPP
#define SCENE_HPP

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Plane.hpp"
#include "Window.hpp"

class Scene{
public:
    Window *win;
    struct GLFWwindow *win_events; // window to check for events

    // uniform data defining scene positiion and lighting
    // must match vec4 for shaders
    struct SceneData{
        glm::mat4 proj_from_world, world_from_proj;
        // xyz is the direction of the light, w is ambient intensity
        glm::vec4 light_vector;
    } scene;
    GLuint sceneID;

    // Window data
    int width, height;

    // view properties
    float dist_from_origin;
    float pan, tilt;
    float pan_rate, tilt_rate;

    // event data
    bool win_resize;        // window was resized
    bool left_press;        // left mouse button down
    double mouseX, mouseY;  // last known location of mouse

    // time of last frame
    double prev_time;

    // objects in scene
    Plane *ground;
    Plane *image;

    Scene(Window *window);

    // update scene
    void Update(double current_time = glfwGetTime());

    // mouse event handling
    void MousePress();
};

#endif