//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/Scene.h"

void zl::Scene::onInitializeScene() {

}

void zl::Scene::onLoadResources() {

}

void zl::Scene::onDraw(sf::RenderTarget &rt) {

}

void zl::Scene::onUpdateState() {

}

void zl::Scene::onDestroy() {

}

void zl::Scene::onSFMLEvent(sf::Event &event) {

}

void zl::Scene::attach(Entity *entity) {
    if (entity->getParentWindow() == nullptr)
        entity->setParentWindow(m_pParentWindow);

    m_entitiesContainer.emplace_back(entity);
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

void zl::Scene::setParentWindow(sf::RenderWindow *window) {
    m_pParentWindow = window;
}


void zl::Scene::updateState() {
    onUpdateState();
    for (auto &entity: m_entitiesContainer) {
        entity->updateState();
    }
}

void zl::Scene::initializeScene() {
    onInitializeScene();
    onLoadResources();

}

zl::str &zl::Scene::getNewScene() {
    return m_pNewScene;
}

void zl::Scene::setNewScene(const zl::str &sceneName) {
    m_pNewScene = sceneName;
}
