#include "Engine.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <functional>
#include <iostream>

Engine::Engine(
    std::string &&label
): _label(std::move(label)) {}

Engine::~Engine() {
    glfwDestroyWindow(_window);
}

void Engine::init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto monitor = glfwGetPrimaryMonitor();
    if (!monitor) {
        throw std::runtime_error("Failed to find main monitor");
    }
    auto vidMode = glfwGetVideoMode(monitor);
    _width = vidMode->width;
    _height = vidMode->height;

    _window = glfwCreateWindow(_width, _height, _label.c_str(), nullptr, nullptr);
    if (_window == nullptr) {
        throw std::runtime_error("Failed to initialize window surface");
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize OpenGL");
    }

    _init = true;
}

int Engine::start() {
    if (!_init) {
        throw std::runtime_error("Engine must be initialized first");
    }

    _game.init();
    _game.start();

    while (!glfwWindowShouldClose(_window))
    {
        processInput();

        try {
            _game.update();
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        glClearColor(0.5f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);   
        
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void Engine::processInput() {
    if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(_window, true);
    }
}
