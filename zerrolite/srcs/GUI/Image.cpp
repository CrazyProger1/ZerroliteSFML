//
// Created by crazy on 12.01.2022.
//

#include "../../include/GUI/Image.h"

zl::Image::Image() {

}

zl::Image::Image(const zl::str &path) {
    m_imagePath = path;
    init();
}

void zl::Image::initialize() {
    setType("image");
    init();
}

void zl::Image::init() {
    m_texture.loadFromFile(m_imagePath);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(getPosition());

    sf::Vector2u originalSize = m_texture.getSize();
    zl::fVector scale = m_sprite.getScale();
    m_size.x = originalSize.x * scale.x;
    m_size.y = originalSize.y * scale.y;

}

void zl::Image::draw(sf::RenderTarget &rt) {
    rt.draw(m_sprite);
}

void zl::Image::updateState() {

}

void zl::Image::setSize(const zl::fVector &size) {
    sf::Vector2u originalSize = m_texture.getSize();

    zl::fVector scale = {size.x / originalSize.x, size.y / originalSize.y};
    m_sprite.setScale(scale);
    init();
}


void zl::Image::setImageFilepath(const zl::str &path) {
    m_imagePath = path;
    init();
}

zl::fVector zl::Image::getSize() {
    return m_size;
}

void zl::Image::setScale(const zl::fVector &scale) {
    m_sprite.setScale(scale);
    init();
}

