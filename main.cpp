#include "zerrolite/zerrolite.h"
//#include "scenes.h"

class Game : public zl::GameCore {

};

class MainMenuScene : public zl::Scene {
    zl::Button tb;

    void onInitializeScene() override {
        tb.setSize(100, 20);
        tb.setPosition(100, 100);
        tb.setCornerRadius(10);
        tb.setBorderWidth(4);
        attach(&tb);
    }
};

int main() {
    Game game;
    sf::RenderWindow window(sf::VideoMode(640, 480), "ZSB 0.0.0");
    game.setMainWindow(&window);
    game.addScene("main menu", new MainMenuScene);
    game.setActiveScene("main menu");
    game.run();
//
////    for (auto &mode: sf::VideoMode::getFullscreenModes()) {
////        std::cout << mode.width << "X" << mode.height << std::endl;
////    }
//    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake");
//
//
//    window.setVerticalSyncEnabled(true);
//
//    game.setMainWindow(&window);
//
//    game.addScene("menu", new MenuScene);
//    game.addScene("game", new GameScene);
//    game.setActiveScene("menu");
//    game.run();



}