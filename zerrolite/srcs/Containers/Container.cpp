//
// Created by crazy on 17.01.2022.
//

#include "../../include/Containers/Container.h"

void zl::Container::initialize() {}

void zl::Container::setPosition(const sf::Vector2f &position) {
    m_position = position;
    initialize();
}

void zl::Container::setPosition(float x, float y) {
    m_position.x = x;
    m_position.y = y;
    initialize();
}


sf::Vector2f &zl::Container::getPosition() {
    return m_position;
}

void zl::Container::move(const sf::Vector2f &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
    initialize();
}

void zl::Container::move(float offsetX, float offsetY) {
    m_position.x += offsetX;
    m_position.y += offsetY;
    initialize();
}









