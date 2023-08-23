#pragma once
#include <string>
#include "../Game/Game.hpp"

class Engine {
public:
    Engine(
        std::string&& label
    );
    ~Engine();

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

private:
    bool _init = false;
};
