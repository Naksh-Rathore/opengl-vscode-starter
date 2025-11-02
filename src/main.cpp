#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

bool initializeLibraries(GLFWwindow *&window);

int main() {
    GLFWwindow *window{};

    if (!initializeLibraries(window)) return EXIT_FAILURE;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);


        glfwPollEvents();
        glfwSwapBuffers(window);
    } 

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

bool initializeLibraries(GLFWwindow *&window) {
    if (!glfwInit()) {
        std::cerr << "GFLW initialization error" << "\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL", nullptr, nullptr);

    if (window == nullptr || window == NULL) {
        std::cerr << "Window couldn't be created" << "\n";
        glfwTerminate();

        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress )) {
        std::cerr << "GLAD setup failed" << "\n";
        return false;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    return true;
}
