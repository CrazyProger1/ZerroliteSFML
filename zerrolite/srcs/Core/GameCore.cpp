//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/GameCore.h"

zl::GameCore::GameCore(sf::RenderWindow *mainWindow) {
    m_pMainWindow = mainWindow;
}

zl::GameCore::GameCore() = default;

void zl::GameCore::tick() {
    handleSFMLEvents();
    m_pActiveScene->draw(*m_pMainWindow);
    m_pActiveScene->updateState();

    str &newScene = m_pActiveScene->getNewScene();
    if (!newScene.empty()) {
        m_pActiveScene->onDestroy();
        setActiveScene(newScene);
    }
}

void zl::GameCore::run() {
    while (m_pMainWindow->isOpen())
        tick();

}


void zl::GameCore::setMainWindow(sf::RenderWindow *window) {
    m_pMainWindow = window;
}

void zl::GameCore::handleSFMLEvents() {
    sf::Event event{};
    while (m_pMainWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_pMainWindow->close();

        m_pActiveScene->handleSFMLEvent(event);

    }
}

void zl::GameCore::terminate() {
    m_pMainWindow->close();
}

void zl::GameCore::addScene(const zl::str &name, zl::Scene *scene) {
    m_scenes[name] = scene;
}

void zl::GameCore::setActiveScene(const zl::str &name) {
    m_pActiveScene = m_scenes[name];
    m_pActiveScene->setParentWindow(m_pMainWindow);
    m_pActiveScene->initializeScene();

}

