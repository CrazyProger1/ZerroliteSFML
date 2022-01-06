//
// Created by crazy on 04.01.2022.
//

#include "../include/Entity.h"


namespace zl {

    void Entity::draw(sf::RenderTarget &renderTarget) {

    }

    void Entity::handleSFMLEvent(sf::Event &event) {

    }

    void Entity::setPosition(fCoords coords) {
        m_position = coords;
    }

    void Entity::move(fCoords &offset) {
        m_position.x += offset.x;
        m_position.y += offset.y;
    }

    fCoords &Entity::getPosition() {
        return m_position;
    }

    Entity::Entity(fCoords &position) {
        m_position = position;
    }

    void Entity::setParentWindow(sf::RenderWindow &window) {
        m_pParentWindow = &window;
    }

    sf::RenderWindow *Entity::getParentWindow() {
        return m_pParentWindow;
    }


    Entity::Entity() = default;
}