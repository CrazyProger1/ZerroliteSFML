#include <iostream>
#include "zerrolite/include/GameCore.h"
#include <SFML/Graphics.hpp>

class Game : public zl::GameCore {

};

int main() {

    sf::RenderWindow window({640, 480}, "hello world");

    Game game;
    game.setMainWindow(&window);

    return 0;
}
