//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/GameCore.h"
#include <chrono>


std::chrono::high_resolution_clock::time_point g_tStart;
std::chrono::high_resolution_clock::time_point g_tEnd;


zl::GameCore::GameCore() = default;

zl::GameCore::GameCore(sf::RenderWindow *mainWindow) {
    m_pMainWindow = mainWindow;
    m_resolution = m_pMainWindow->getSize();
}

void zl::GameCore::tick() {
    g_tStart = std::chrono::high_resolution_clock::now();

    handleSFMLEvents();

    m_pActiveScene->draw(*m_pMainWindow);

    m_pActiveScene->updateState();

    auto &rsNewScene = m_pActiveScene->getNewScene();

    if (!rsNewScene.empty()) {
        m_pActiveScene->onDestroy();
        setActiveScene(rsNewScene);
    }

    g_tEnd = std::chrono::high_resolution_clock::now();

    m_iFps = (float) 1e9 / (float) std::chrono::duration_cast<std::chrono::nanoseconds>(g_tEnd - g_tStart).count();
}

void zl::GameCore::handleSFMLEvents() {
    sf::Event event{};
    while (m_pMainWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_pMainWindow->close();

        m_pActiveScene->handleSFMLEvent(event);
    }
}

void zl::GameCore::setMainWindow(sf::RenderWindow *window) {
    m_pMainWindow = window;
    m_resolution = m_pMainWindow->getSize();
}

void zl::GameCore::setActiveScene(const zl::TStr &name) {
    m_pActiveScene = m_scenes[name];
    m_pActiveScene->setParentWindow(m_pMainWindow);
    m_pActiveScene->initializeScene();

}

void zl::GameCore::addScene(const zl::TStr &name, zl::Scene *scene) {
    m_scenes[name] = scene;
}


zl::Scene *zl::GameCore::getActiveScene() {
    return m_pActiveScene;
}

sf::RenderWindow *zl::GameCore::getMainWindow() {
    return m_pMainWindow;
}

sf::Vector2u &zl::GameCore::getWindowResolution() {
    return m_resolution;
}


int zl::GameCore::getFps() const {
    return m_iFps;
}

void zl::GameCore::run() {
    if (m_pMainWindow == nullptr) {
        std::cerr << "Window did not set" << std::endl;
        throw std::exception();
    }

    if (m_pActiveScene == nullptr) {
        std::cerr << "Scene did not set" << std::endl;
        throw std::exception();
    }

    while (m_pMainWindow->isOpen())
        tick();

}

void zl::GameCore::terminate() {
    m_pMainWindow->close();
}







