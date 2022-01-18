#include "zerrolite/zerrolite.h"
#include "scenes.h"

class Game : public zl::GameCore {

};

int main() {
    Game game;

//    for (auto &mode: sf::VideoMode::getFullscreenModes()) {
//        std::cout << mode.width << "X" << mode.height << std::endl;
//    }
    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake");


    window.setVerticalSyncEnabled(true);

    game.setMainWindow(&window);

    game.addScene("menu", new MenuScene);
    game.addScene("game", new GameScene);
    game.setActiveScene("menu");
    game.run();

}