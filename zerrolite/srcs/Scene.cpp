//
// Created by crazy on 27.12.2021.
//

#include "../include/Scene.h"


namespace zl {

    void Scene::draw(sf::RenderWindow &renderWindow) {
        renderWindow.clear();
        for (auto &entity: m_entitiesContainer) {
            entity->draw(renderWindow);
        }
        renderWindow.display();
    }

    void Scene::handleSFMLEvent(sf::Event &event) {
        for (auto &entity: m_entitiesContainer) {
            entity->handleSFMLEvent(event);
        }
    }

    void Scene::initializeEntities() {

    }

    void Scene::updateState() {

    }

    void Scene::attach(Entity &entity) {
        entity.setParentWindow(*m_pParentWindow);
        m_entitiesContainer.emplace_back(&entity);
    }

    void Scene::setSelfReference(Scene *scene) {
        m_pActiveScene = scene;
    }

    void Scene::setActiveScene(Scene *scene) {

        m_pActiveScene = scene;
        m_pActiveScene->setSelfReference(m_pActiveScene);
        m_pActiveScene->initializeEntities();
        m_pActiveScene->setParentWindow(*m_pParentWindow);

    }

    void Scene::setParentWindow(sf::RenderWindow &window) {
        m_pParentWindow = &window;
    }

}