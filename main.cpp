#include "zerrolite/zerrolite.h"
#include "ZSB/zsb.h"


int main() {
    Game game;

    Game::getGlobalStorage()->setValue("lang", "ru");

    auto windowConfig = zl::ConfigManager::loadWindowConfig("../resources/config/window.json");

    auto iWindowStyle = sf::Style::Default;

    if (windowConfig.fullscreen)
        iWindowStyle = sf::Style::Fullscreen;

    sf::RenderWindow window(sf::VideoMode(windowConfig.width, windowConfig.height), windowConfig.title, iWindowStyle);

    window.setVerticalSyncEnabled(true);

    game.setMainWindow(&window);
    game.addScene("MainMenu", new MainMenuScene);
    game.addScene("OfflineGame", new OfflineGameScene);
    game.setActiveScene("MainMenu");

    game.run();
}

