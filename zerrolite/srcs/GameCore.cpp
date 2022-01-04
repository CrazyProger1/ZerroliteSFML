//
// Created by crazy on 27.12.2021.
//

#include "../include/GameCore.h"

namespace zl {

    GameCore::GameCore() = default;

    GameCore::GameCore(sf::RenderWindow *mainWindow) {
        m_pMainWindow = mainWindow;
    }

    void GameCore::setMainWindow(sf::RenderWindow *mainWindow) {
        m_pMainWindow = mainWindow;
    }

    void GameCore::run() {
        while (m_pMainWindow->isOpen()) {
            tick();
        }
    }

    void GameCore::setActiveScene(Scene *scene) {
        m_pActiveScene = scene;
        m_pActiveScene->entitiesInitialization();
    }

    void GameCore::handleSFMLEvents() {
        sf::Event event{};
        while (m_pMainWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_pMainWindow->close();

            m_pActiveScene->handleSFMLEvent(event);
        }
    }

    void GameCore::tick() {
        handleSFMLEvents();

        m_pActiveScene->updateState();
        m_pActiveScene->draw(*m_pMainWindow);
    }

    void GameCore::terminate() {
        m_pMainWindow->close();
    }


}
