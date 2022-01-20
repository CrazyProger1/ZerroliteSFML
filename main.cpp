#include "zerrolite/zerrolite.h"
#include "ZSB/zsb.h"


int main() {
    Game game;

    auto windowConfig = zl::ConfigManager::loadWindowConfig("../resources/config/window.json");

    auto iStyle = sf::Style::Default;

    if (windowConfig.fullscreen)
        iStyle = sf::Style::Fullscreen;

    sf::RenderWindow window(sf::VideoMode(windowConfig.width, windowConfig.height), windowConfig.title, iStyle);

    window.setVerticalSyncEnabled(true);

    game.setMainWindow(&window);
    game.addScene("MainMenu", new MainMenuScene);
    game.setActiveScene("MainMenu");

    game.run();
}

