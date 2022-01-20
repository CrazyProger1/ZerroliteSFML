#include "zerrolite/zerrolite.h"
#include "ZSB/zsb.h"


int main() {
    Game game;

    auto windowConfig = zl::ConfigManager::loadWindowConfig("../resources/config/window.json");

    auto iWindowStyle = sf::Style::Default;

    if (windowConfig.fullscreen)
        iWindowStyle = sf::Style::Fullscreen;

    sf::RenderWindow window(sf::VideoMode(windowConfig.width, windowConfig.height), windowConfig.title, iWindowStyle);

    window.setVerticalSyncEnabled(true);

    game.setMainWindow(&window);
    game.addScene("MainMenu", new MainMenuScene);
    game.addScene("GameSelection", new GameSelectionScene);
    game.setActiveScene("MainMenu");


    game.run();
}

