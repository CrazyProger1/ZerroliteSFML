//
// Created by crazy on 18.01.2022.
//


#include "../../include/Core/Actor.h"

zl::Actor::Actor() = default;

zl::Actor::Actor(const sf::Vector2f &position) : Entity(position) {
    m_position = position;
}


void zl::Actor::setPosition(const sf::Vector2f &position) {
    if (position == m_position)return;
    m_position = position;
    m_pSprite->setPosition(m_position);
}

void zl::Actor::setPosition(float x, float y) {
    if (x == m_position.x && y == m_position.y)return;
    m_position.x = x;
    m_position.y = y;
    m_pSprite->setPosition(m_position);
}

void zl::Actor::setSprite(sf::Sprite *sprite) {
    m_pSprite = sprite;


    if (m_iActiveAppearanceId < 0) {
        std::cerr << "Appearance did not set" << std::endl;
        throw std::exception();
    }

    m_pSprite->setTexture(m_appearances[(int) m_iActiveAppearanceId]);

    m_size = m_pSprite->getTexture()->getSize();

    m_pSprite->setOrigin(m_size.x / 2, m_size.y / 2);
}

void zl::Actor::setRotation(float angle) {
    m_fltAngle = angle;
    m_pSprite->setRotation(angle);

}

void zl::Actor::setSpeed(float speed) {
    m_fltSpeed = speed;
}

void zl::Actor::setAppearance(unsigned int appearanceId) {
    m_iActiveAppearanceId = (int) appearanceId;
    m_pSprite->setTexture(m_appearances[(int) appearanceId]);
}

void zl::Actor::addAppearance(unsigned int appearanceId, sf::Texture &texture) {
    m_appearances[(int) appearanceId] = texture;
    m_iActiveAppearanceId = (int) appearanceId;
}

void zl::Actor::calculateSpeed() {
    m_speedVector.x = (float) m_fltSpeed * (float) std::cos(m_fltAngle * (3.14159265 / 180));
    m_speedVector.y = (float) m_fltSpeed * (float) std::sin(m_fltAngle * (3.14159265 / 180));
}

void zl::Actor::draw(sf::RenderTarget &rt) {
    onDraw(rt);
    rt.draw(*m_pSprite);
}

void zl::Actor::handleSFMLEvent(sf::Event &event) {
    onSFMLEvent(event);
}

void zl::Actor::updateState() {
    calculateSpeed();
    onUpdateState();
}

void zl::Actor::rotate(float angle) {
    m_fltAngle += angle;
    m_pSprite->rotate(angle);
}


void zl::Actor::move(const sf::Vector2f &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
    m_pSprite->setPosition(m_position);
}

void zl::Actor::move(float offsetX, float offsetY) {
    m_position.x += offsetX;
    m_position.y += offsetY;
    m_pSprite->setPosition(m_position);
}

void zl::Actor::turnToMouseCursor() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*getParentWindow());
    float fltWDist, fltHDist;
    fltWDist = (float) mousePos.x - m_position.x;
    fltHDist = (float) mousePos.y - m_position.y;
    setRotation(std::atan2(fltHDist, fltWDist) * 180 / 3.14159265);

}

void zl::Actor::onAttach() {
    onLoadResources();
    onInitializeActor();
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


void zl::Actor::onInitializeActor() {}

void zl::Actor::onLoadResources() {}

void zl::Actor::onDraw(sf::RenderTarget &rt) {}

void zl::Actor::onUpdateState() {}

void zl::Actor::onSFMLEvent(sf::Event &event) {}












