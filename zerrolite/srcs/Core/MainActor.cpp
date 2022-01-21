//
// Created by crazy on 18.01.2022.
//

#include <iostream>
#include "../../include/Core/MainActor.h"

void zl::MainActor::initialize() {
    Actor::initialize();
    setType("player");
}

std::vector<int> &zl::MainActor::getPressedKeys() {
    return m_pressedKeys;
}


void zl::MainActor::handleSFMLEvent(sf::Event &event) {
    onSFMLEvent(event);


    if (event.type == sf::Event::KeyPressed) {
        if (std::find(m_pressedKeys.begin(), m_pressedKeys.end(), event.key.code) == m_pressedKeys.end())
            m_pressedKeys.push_back(event.key.code);
    }


    if (event.type == sf::Event::KeyReleased)
        m_pressedKeys.erase(std::remove(m_pressedKeys.begin(), m_pressedKeys.end(), event.key.code),
                            m_pressedKeys.end());

}

void zl::MainActor::onSFMLEvent(sf::Event &event) {}

void zl::MainActor::onUpdateState() {}

void zl::MainActor::onLoadResources() {}

void zl::MainActor::onDraw(sf::RenderTarget &rt) {}


void zl::MainActor::onInitializeActor() {

}

void zl::MainActor::moveForward(float speedFactor) {
    Actor::moveForward(speedFactor);
}

void zl::MainActor::moveBack(float speedFactor) {
    Actor::moveBack(speedFactor);
}

void zl::MainActor::moveRight(float speedFactor) {
    Actor::moveRight(speedFactor);
}

void zl::MainActor::moveLeft(float speedFactor) {
    Actor::moveLeft(speedFactor);
}


