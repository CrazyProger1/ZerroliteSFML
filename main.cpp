#include <iostream>
#include "zerrolite/include/GameCore.h"
#include "zerrolite/include/Scene.h"
#include <SFML/Graphics.hpp>
#include "zerrolite/include/Entity.h"
#include "zerrolite/include/GUI/Button.h"
#include "zerrolite/include/GUI/Text.h"

class Game : public zl::GameCore {

};

class SinglePlayer : public zl::Scene {
    void initializeEntities() override {

    }
};

class MainMenu : public zl::Scene {
//    zl::Button buttonPlay;
    zl::Text text;


    void initializeEntities() override {
        text.setPosition({100, 100});
        attach(text);
//        buttonPlay.setPosition({100, 100});
//        attach(buttonPlay);
    }
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
