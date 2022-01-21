//
// Created by crazy on 18.01.2022.
//


#include "../../include/Core/Actor.h"

zl::Actor::Actor() = default;

zl::Actor::Actor(const sf::Vector2f &position) : Entity(position) {
    m_position = position;
}

void zl::Actor::initialize() {
    m_originCircle.setRadius(2.0f);
    m_originCircle.setFillColor(sf::Color(255, 0, 0));
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

    sf::Vector2f originOffset;

    try {
        originOffset = m_originOffsets.at(m_iActiveAppearanceId);
    } catch (std::out_of_range &) {

    }
    m_pSprite->setOrigin(m_size.x / 2 + originOffset.x, m_size.y / 2 + originOffset.y);
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

    sf::Texture &texture = m_appearances[m_iActiveAppearanceId];

    sf::Vector2f originOffset;


    try {
        originOffset = m_originOffsets.at((int) appearanceId);
    } catch (std::out_of_range &) {

    }
    m_size = texture.getSize();
    if (m_pSprite != nullptr) {
        m_pSprite->setTexture(texture);
        m_pSprite->setOrigin(m_size.x / 2 + originOffset.x, m_size.y / 2 + originOffset.y);
    }
}

void zl::Actor::addAppearance(unsigned int appearanceId, sf::Texture &texture, const sf::Vector2f &originOffset) {
    m_appearances[(int) appearanceId] = texture;

    if (originOffset.x != 0 || originOffset.y != 0)
        m_originOffsets[(int) appearanceId] = originOffset;

    m_iActiveAppearanceId = (int) appearanceId;
}

sf::Vector2f &zl::Actor::getPosition() {
    return m_position;
}


sf::Vector2f zl::Actor::calculateSpeed(float angle, float speed) {
    sf::Vector2f speedVector;
    speedVector.x = (float) speed * (float) std::cos(angle * (3.14159265 / 180));
    speedVector.y = (float) speed * (float) std::sin(angle * (3.14159265 / 180));
    return speedVector;
}

void zl::Actor::draw(sf::RenderTarget &rt) {
    rt.draw(*m_pSprite);
    if (m_bOriginShowed)
        rt.draw(m_originCircle);
    onDraw(rt);
}

void zl::Actor::handleSFMLEvent(sf::Event &event) {
    onSFMLEvent(event);
}

void zl::Actor::updateState() {
//    calculateSpeed();
    if (m_bOriginShowed)
        m_originCircle.setPosition(getPosition());


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

void zl::Actor::showOrigin() {
    m_bOriginShowed = true;
}

void zl::Actor::hideOrigin() {
    m_bOriginShowed = false;
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


void zl::Actor::moveForward(float speedFactor) {
    move(calculateSpeed(m_fltAngle, m_fltSpeed * speedFactor));
}

void zl::Actor::moveBack(float speedFactor) {
    sf::Vector2f speedVector = calculateSpeed(m_fltAngle, m_fltSpeed * speedFactor);
    move({-speedVector.x, -speedVector.y});
}

void zl::Actor::moveRight(float speedFactor) {
    sf::Vector2f speedVector = calculateSpeed(m_fltAngle + 90, m_fltSpeed * speedFactor);
    move({speedVector.x, speedVector.y});
}

void zl::Actor::moveLeft(float speedFactor) {
    sf::Vector2f speedVector = calculateSpeed(m_fltAngle + 90, m_fltSpeed * speedFactor);
    move({-speedVector.x, -speedVector.y});
}


void zl::Actor::onInitializeActor() {}

void zl::Actor::onLoadResources() {}

void zl::Actor::onDraw(sf::RenderTarget &rt) {}

void zl::Actor::onUpdateState() {}

void zl::Actor::onSFMLEvent(sf::Event &event) {}















