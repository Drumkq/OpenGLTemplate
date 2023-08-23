#pragma once
#include <string>
#include "../Game/Game.hpp"

class Engine {
public:
    Engine(
        const std::string& label
    );

    void init();
    int start();

private:
    void processInput();

private:
    Game _game;

private:
    const std::string _label;
    int _width;
    int _height;

    class GLFWwindow* _window;
    class GLFWmonitor* _mainMonitor;

private:
    bool _init = false;
};
