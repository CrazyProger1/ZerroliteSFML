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

    }

    void Scene::entitiesInitialization() {

    }

    void Scene::updateState() {

    }

    void Scene::attach(Entity &entity) {
        m_entitiesContainer.emplace_back(&entity);
    }
}