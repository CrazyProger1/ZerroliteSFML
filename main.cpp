#include "zerrolite/zerrolite.h"
#include "scenes.h"

class Game : public zl::GameCore {

};

int main() {
    Game game;
    MainMenu mm;
    SinglePlayerMenu spm;
    MultiPlayerMenu mpm;
    Shop shop;
    About about;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake");

//    window.setVerticalSyncEnabled(true);

    game.setMainWindow(&window);

    game.addScene("mm", &mm);
    game.addScene("mpm", &mpm);
    game.addScene("spm", &spm);
    game.addScene("shop", &shop);
    game.addScene("about", &about);

    game.setActiveScene("mm");
    game.run();

}