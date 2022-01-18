//
// Created by crazy on 18.01.2022.
//


#include "../../include/Core/Actor.h"

void zl::Actor::move(const fVector &offset) {
//    if (offset.x == 0 && offset.y == 0) return;
    m_position.x += offset.x;
    m_position.y += offset.y;
    m_sprite->setPosition(m_position);
}

void zl::Actor::setPosition(const fVector &position) {
    if (position == m_position)return;
    m_position = position;
    m_sprite->setPosition(position);
}

void zl::Actor::initialize() {

}

void zl::Actor::setSprite(sf::Sprite *sprite) {
    m_sprite = sprite;
    uVector spriteSize = m_sprite->getTexture()->getSize();
    m_sprite->setOrigin(spriteSize.x / 2, spriteSize.y / 2);
}

void zl::Actor::draw(sf::RenderTarget &rt) {
    rt.draw(*m_sprite);
}

void zl::Actor::rotate(float angle) {
    m_angle += angle;
    m_sprite->rotate(angle);
}

void zl::Actor::setRotation(float angle) {
    m_angle = angle;
    m_sprite->setRotation(angle);

}

void zl::Actor::turnToMouseCursor() {
    iVector mousePos = sf::Mouse::getPosition(*getParentWindow());
    float wDist, hDist;
    wDist = (float) mousePos.x - m_position.x;
    hDist = (float) mousePos.y - m_position.y;
    setRotation(std::atan2(hDist, wDist) * 180 / 3.14159265);

}