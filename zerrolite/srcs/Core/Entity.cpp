//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/Entity.h"

void zl::Entity::draw(sf::RenderTarget &rt) {

}

void zl::Entity::updateState() {

}

void zl::Entity::handleSFMLEvent(sf::Event &event) {

}

void zl::Entity::move(const fVector &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
    initialize();
}

void zl::Entity::setPosition(const fVector &position) {
    m_position = position;
    initialize();
}

void zl::Entity::setParentWindow(sf::RenderWindow *window) {
    m_pParentWindow = window;
}

sf::RenderWindow *zl::Entity::getParentWindow() {
    return m_pParentWindow;
}

zl::fVector &zl::Entity::getPosition() {
    return m_position;
}

void zl::Entity::initialize() {

}

void zl::Entity::setType(const zl::str &type) {
    m_type = type;
}

zl::str &zl::Entity::getType() {
    return m_type;
}

void zl::Entity::onAttach() {

}
