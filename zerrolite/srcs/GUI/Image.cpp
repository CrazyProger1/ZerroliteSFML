//
// Created by crazy on 12.01.2022.
//

#include "../../include/GUI/Image.h"

zl::Image::Image() = default;

zl::Image::Image(const zl::TStr &path) {
    m_sImagePath = path;
}

void zl::Image::initialize() {
    setType("image");

    m_texture.loadFromFile(m_sImagePath);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(getPosition());

    sf::Vector2u originalSize = m_texture.getSize();
    sf::Vector2f scale = m_sprite.getScale();
    m_size.x = originalSize.x * scale.x;
    m_size.y = originalSize.y * scale.y;
}

void zl::Image::setSize(const sf::Vector2f &size) {
    sf::Vector2u originalSize = m_texture.getSize();

    sf::Vector2f scale = {size.x / originalSize.x, size.y / originalSize.y};
    m_sprite.setScale(scale);
    initialize();
}

void zl::Image::setSize(float w, float h) {
    sf::Vector2u originalSize = m_texture.getSize();

    sf::Vector2f scale = {w / originalSize.x, h / originalSize.y};
    m_sprite.setScale(scale);
    initialize();
}


void zl::Image::setImageFilepath(const zl::TStr &path) {
    m_sImagePath = path;
    initialize();
}

void zl::Image::setScale(const sf::Vector2f &scale) {
    m_sprite.setScale(scale);
    initialize();
}

void zl::Image::setScale(float factorX, float factorY) {
    m_sprite.setScale(factorX, factorY);
    initialize();
}

sf::Vector2f zl::Image::getSize() {
    return m_size;
}


void zl::Image::draw(sf::RenderTarget &rt) {
    rt.draw(m_sprite);
}

void zl::Image::updateState() {

}








