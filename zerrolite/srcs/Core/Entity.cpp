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

void zl::Entity::move(zl::fVector offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
}

void zl::Entity::setPosition(zl::fVector position) {
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
