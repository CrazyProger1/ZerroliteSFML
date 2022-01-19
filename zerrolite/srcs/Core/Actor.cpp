//
// Created by crazy on 18.01.2022.
//


#include "../../include/Core/Actor.h"

#include <cmath>

void zl::Actor::move(const fVector &offset) {
//    if (offset.x == 0 && offset.y == 0) return;
    m_position.x += offset.x;
    m_position.y += offset.y;
    m_pSprite->setPosition(m_position);
}

void zl::Actor::setPosition(const fVector &position) {
    if (position == m_position)return;
    m_position = position;
    m_pSprite->setPosition(position);
}

void zl::Actor::initialize() {

}

void zl::Actor::setSprite(sf::Sprite *sprite) {
    m_pSprite = sprite;


    if (m_activeAppearanceId == -1) {
        std::cerr << "Appearance does not set" << std::endl;
        throw std::exception();
    }
    m_pSprite->setTexture(m_appearances[(int) m_activeAppearanceId]);

    m_size = m_pSprite->getTexture()->getSize();
    m_pSprite->setOrigin(m_size.x / 2, m_size.y / 2);
}

void zl::Actor::draw(sf::RenderTarget &rt) {
    onDraw(rt);
    rt.draw(*m_pSprite);
}

void zl::Actor::rotate(float angle) {
    m_angle += angle;
    m_pSprite->rotate(angle);
}

void zl::Actor::setRotation(float angle) {
    m_angle = angle;
    m_pSprite->setRotation(angle);

}

void zl::Actor::turnToMouseCursor() {
    iVector mousePos = sf::Mouse::getPosition(*getParentWindow());
    float wDist, hDist;
    wDist = (float) mousePos.x - m_position.x;
    hDist = (float) mousePos.y - m_position.y;
    setRotation(std::atan2(hDist, wDist) * 180 / 3.14159265);

}

void zl::Actor::addAppearance(unsigned int appearanceId, sf::Texture &texture) {
    m_appearances[(int) appearanceId] = texture;
    m_activeAppearanceId = (int) appearanceId;
}

void zl::Actor::setAppearance(unsigned int appearanceId) {
    m_activeAppearanceId = (int) appearanceId;
    m_pSprite->setTexture(m_appearances[(int) appearanceId]);
}

void zl::Actor::onInitializeActor() {

}

void zl::Actor::onLoadResources() {

}

void zl::Actor::onDraw(sf::RenderTarget &rt) {

}

void zl::Actor::onUpdateState() {

}

void zl::Actor::onDestroy() {

}

void zl::Actor::onSFMLEvent(sf::Event &event) {

}

void zl::Actor::onAttach() {
    onLoadResources();
    onInitializeActor();
}

void zl::Actor::handleSFMLEvent(sf::Event &event) {
    onSFMLEvent(event);
}

void zl::Actor::updateState() {
    calculateSpeed();
    onUpdateState();
}

void zl::Actor::moveForward() {

    move(m_speedVector);
}

void zl::Actor::moveBack() {
    move({-m_speedVector.x, -m_speedVector.y});
}

void zl::Actor::moveRight() {

}

void zl::Actor::moveLeft() {

}

void zl::Actor::calculateSpeed() {
    m_speedVector.x = (float) m_speed * (float) std::cos(m_angle * (3.14159265 / 180));
    m_speedVector.y = (float) m_speed * (float) std::sin(m_angle * (3.14159265 / 180));
}

void zl::Actor::setSpeed(float speed) {
    m_speed = speed;
}






