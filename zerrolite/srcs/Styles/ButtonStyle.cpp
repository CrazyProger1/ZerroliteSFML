//
// Created by crazy on 12.01.2022.
//

#include "../../include/Styles/ButtonStyle.h"

zl::ButtonStyle::ButtonStyle(const sf::Vector2f &size,
                             const zl::RGBAColor &color,
                             const zl::RGBAColor &hoverColor,
                             const sf::Vector2f &textOffset,
                             const sf::Vector2f &imageOffset,
                             int borderWidth,
                             const zl::RGBAColor &borderColor,
                             bool centerText,
                             bool centerImage,
                             int cornerRadius,
                             bool isDeactivated,
                             const RGBAColor &deactivatedColor) {
    m_size = size;
    m_color = color;
    m_hoverColor = hoverColor;
    m_textOffset = textOffset;
    m_imageOffset = imageOffset;
    m_iBorderWidth = borderWidth;
    m_borderColor = borderColor;
    m_bCenterText = centerText;
    m_bCenterImage = centerImage;
    m_iCornerRadius = cornerRadius;
    m_bIsDeactivated = isDeactivated;
    m_deactivatedColor = deactivatedColor;


}


sf::Vector2f &zl::ButtonStyle::getSize() {
    return m_size;
}

sf::Vector2f &zl::ButtonStyle::getTextOffset() {
    return m_textOffset;
}

int zl::ButtonStyle::getBorderWidth() const {
    return m_iBorderWidth;
}

int zl::ButtonStyle::getCornerRadius() const {
    return m_iCornerRadius;
}

zl::RGBAColor &zl::ButtonStyle::getColor() {
    return m_color;
}

zl::RGBAColor &zl::ButtonStyle::getHoverColor() {
    return m_hoverColor;
}

zl::RGBAColor &zl::ButtonStyle::getBorderColor() {
    return m_borderColor;
}

zl::RGBAColor &zl::ButtonStyle::getDeactivatedColor() {
    return m_deactivatedColor;
}

sf::Vector2f &zl::ButtonStyle::getImageOffset() {
    return m_imageOffset;
}


bool zl::ButtonStyle::isDeactivated() const {
    return m_bIsDeactivated;
}

bool zl::ButtonStyle::centerText() const {
    return m_bCenterText;
}

bool zl::ButtonStyle::centerImage() const {
    return m_bCenterImage;
}















