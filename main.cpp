#include "zerrolite/zerrolite.h"
#include "scenes.h"

class Game : public zl::GameCore {

};

int main() {
    Game game;
    MainMenu mainMenu;
    SinglePlayerMenu spm;
    MultiPlayerMenu mpm;

    sf::RenderWindow window(sf::VideoMode(640, 480), "hello world");

    game.setMainWindow(&window);

    game.addScene("main menu", &mainMenu);
    game.addScene("mpm", &mpm);
    game.addScene("spm", &spm);

    game.setActiveScene("main menu");
    game.run();

}