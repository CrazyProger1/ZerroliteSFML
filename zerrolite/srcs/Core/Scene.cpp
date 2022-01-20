//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/Scene.h"


void zl::Scene::attach(Entity *entity) {
    if (entity->getParentWindow() == nullptr)
        entity->setParentWindow(m_pParentWindow);

    entity->initialize();
    entity->onAttach();

    m_entitiesContainer.emplace_back(entity);
}

void zl::Scene::attach(zl::Container *container) {
    for (auto &entity: container->getEntities()) {
        if (entity->getParentWindow() == nullptr)
            entity->setParentWindow(m_pParentWindow);

        entity->initialize();
        entity->onAttach();
        m_entitiesContainer.emplace_back(entity);
    }
}

void zl::Scene::draw(sf::RenderTarget &rt) {

    m_pParentWindow->clear();
    onDraw(rt);
    for (auto &entity: m_entitiesContainer) {
        entity->draw(rt);
    }

    m_pParentWindow->display();
}

void zl::Scene::handleSFMLEvent(sf::Event &event) {
    onSFMLEvent(event);
    for (auto &entity: m_entitiesContainer) {
        entity->handleSFMLEvent(event);
    }
}

void zl::Scene::updateState() {
    onUpdateState();
    for (auto &entity: m_entitiesContainer) {
        entity->updateState();
    }
}

void zl::Scene::initializeScene() {
    m_entitiesContainer.clear();
    m_sNewScene = "";
    onLoadResources();
    onInitializeScene();
}

void zl::Scene::setParentWindow(sf::RenderWindow *window) {
    m_resolution = window->getSize();
    m_pParentWindow = window;
}

void zl::Scene::setNewScene(const zl::TStr &sceneName) {
    m_sNewScene = sceneName;
}

zl::TStr &zl::Scene::getNewScene() {
    return m_sNewScene;
}


sf::RenderWindow *zl::Scene::getParentWindow() {
    return m_pParentWindow;
}

sf::Vector2u &zl::Scene::getWindowResolution() {
    return m_resolution;
}


void zl::Scene::onInitializeScene() {}

void zl::Scene::onLoadResources() {}

void zl::Scene::onDraw(sf::RenderTarget &rt) {}

void zl::Scene::onUpdateState() {}

void zl::Scene::onDestroy() {}

void zl::Scene::onSFMLEvent(sf::Event &event) {}

