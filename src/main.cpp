#include "Engine/Engine.hpp"

int main() {
    auto engine = Engine("My first OOP window");
    engine.init();

    return engine.start();
}
