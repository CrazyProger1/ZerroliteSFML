//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/GameCore.h"
#include <chrono>
#include <iostream>

std::chrono::high_resolution_clock::time_point start;
std::chrono::high_resolution_clock::time_point end;

zl::GameCore::GameCore(sf::RenderWindow *mainWindow) {
    m_pMainWindow = mainWindow;
}

zl::GameCore::GameCore() = default;

void zl::GameCore::tick() {
    start = std::chrono::high_resolution_clock::now();
    handleSFMLEvents();
    m_pActiveScene->draw(*m_pMainWindow);
    m_pActiveScene->updateState();

    str &newScene = m_pActiveScene->getNewScene();
    if (!newScene.empty()) {
        m_pActiveScene->onDestroy();
        setActiveScene(newScene);
    }

    end = std::chrono::high_resolution_clock::now();

    int fps = (float) 1e9 / (float) std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
//    std::cout << fps << std::endl;
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

