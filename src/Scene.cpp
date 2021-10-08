// author: Colin Seifer
// file: Scene.hpp
// description: handles events and updating the scene.

#include "Scene.hpp"

#ifndef F_PI
#define F_PI 3.1415926f
#endif

// GLFW callbacks must use extern "C"
extern "C" {
    // called whenever the window size changes
    void reshape(GLFWwindow *window, int width, int height) {
        // save window dimensions
        int w, h;
        glfwGetFramebufferSize(window, &w, &h);

        // viewport size matches window size
        glViewport(0, 0, w, h);
    }
}

Scene::Scene(Window *window){
    win = window;
    win_events = win->win;

    glfwSetWindowSizeCallback(win_events, reshape);

    // set initial viewpoint
    dist_from_origin = 34.8f;
    pan = 0.0f;
    tilt = 0.0f;
    pan_rate = tilt_rate = 0.f;

    // mouse data
    left_press = false;
    mouseX = mouseY = 0.f;

    // window data
    width = 1280;
    height = 720;

    // prepare buffer for scene data
    glGenBuffers(1, &sceneID);
    glBindBuffer(GL_UNIFORM_BUFFER, sceneID);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(SceneData), 0, GL_STREAM_DRAW);

    // light direction (xyz) and ambient (w)
    scene.light_vector = glm::vec4(0, 0, -2, 1.f);

    // ground object
    ground = new Plane(glm::vec3(1280, 405, 0), "Scene.jpg", "../data/Scene.jpg");
    image = new Plane(glm::vec3(485, 385, 0.5), "Cover0.jpg", "../data/Cover0.jpg", glm::vec2(-375, 0));
}

void Scene::Update(double current_time){
    // values for silver background
    const float blue_r = 0.163;
    const float blue_g = 0.166;
    const float blue_b = 0.206;
    const float blue_a = 1.f;

    // get time since last update
    double time = current_time - prev_time;

    // clear the last frame and set background
    glClearColor(blue_r, blue_g, blue_b, blue_a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // update pan and tilt
    pan += float(pan_rate * time);
    tilt += float(tilt_rate * time);

    // set remaining scene data based on view
    // uses matrix transformation functions defined in glm namespace
    scene.proj_from_world =
        glm::perspective(F_PI / 4.f, float(win->width / win->height), 1.f, 10000.f)
        * glm::translate(glm::mat4(1), glm::vec3(0,0,-dist_from_origin))
        * glm::rotate(glm::mat4(1), tilt, glm::vec3(1,0,0))
        * glm::rotate(glm::mat4(1), pan, glm::vec3(0,0,1));
    scene.world_from_proj = glm::inverse(scene.proj_from_world);

    // bind scene data
    glBindBuffer(GL_UNIFORM_BUFFER, sceneID);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(SceneData), &scene);

    // draw objects in scene
    ground->Draw(sceneID);
    image->Draw(sceneID);

    // display result of draw
    glfwSwapBuffers(win->win);

    prev_time = current_time;
}

void Scene::MousePress(){

}