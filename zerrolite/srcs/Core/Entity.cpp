//
// Created by crazy on 07.01.2022.
//

#include "../../include/Core/Entity.h"


zl::Entity::Entity(const sf::Vector2f &position) {
    m_position = position;
}

zl::Entity::Entity() = default;


void zl::Entity::setPosition(const sf::Vector2f &position) {
    m_position = position;
    initialize();
}

void zl::Entity::setPosition(float x, float y) {
    m_position.x = x;
    m_position.y = y;
    initialize();
}

void zl::Entity::setParentWindow(sf::RenderWindow *window) {
    m_pParentWindow = window;
    initialize();
}

void zl::Entity::setType(const zl::TStr &type) {
    m_sType = type;
}

void zl::Entity::setSceneClock(sf::Clock *clock) {}

zl::TStr &zl::Entity::getType() {
    return m_sType;
}

sf::RenderWindow *zl::Entity::getParentWindow() {
    return m_pParentWindow;
}

sf::Vector2f &zl::Entity::getPosition() {
    return m_position;
}

void zl::Entity::onAttach() {}

void zl::Entity::initialize() {}

void zl::Entity::draw(sf::RenderTarget &rt) {}

void zl::Entity::updateState() {}

void zl::Entity::handleSFMLEvent(sf::Event &event) {}

void zl::Entity::move(const sf::Vector2f &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
    initialize();
}

void zl::Entity::move(float offsetX, float offsetY) {
    m_position.x += offsetX;
    m_position.y += offsetY;
    initialize();
}






