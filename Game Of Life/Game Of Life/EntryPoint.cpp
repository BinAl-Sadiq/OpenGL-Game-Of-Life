#define GLEW_STATIC

#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "Simulation.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(1280, 720, "Game Of Life", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error GLEW not ok" << std::endl;

    Simulation* simulation = new Simulation(480, 270);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        simulation->simulate();
        simulation->draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    delete simulation;

    glfwTerminate();
    return 0;
}