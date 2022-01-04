#include <iostream>
#include "zerrolite/include/GameCore.h"
#include "zerrolite/include/Scene.h"
#include <SFML/Graphics.hpp>

class Game : public zl::GameCore {

};

class MainMenu : public zl::Scene {

};


int main() {

    sf::RenderWindow window({640, 480}, "hello world");

    Game game;

    MainMenu mainMenuScene;

    game.setMainWindow(&window);
    game.setActiveScene(&mainMenuScene);

    game.run();

    return 0;
}
