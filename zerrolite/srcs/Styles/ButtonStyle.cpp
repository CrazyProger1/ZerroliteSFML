//
// Created by crazy on 12.01.2022.
//

#include "../../include/Styles/ButtonStyle.h"

zl::ButtonStyle::ButtonStyle(const zl::fVector &size,
                             const zl::RGBAColor &color,
                             const zl::RGBAColor &hoverColor,
                             const zl::fVector &textOffset,
                             int borderWidth,
                             const zl::RGBAColor &borderColor,
                             bool centerText,
                             int cornerRadius,
                             bool isDeactivated,
                             const RGBAColor &deactivatedColor) {
    m_size = size;
    m_color = color;
    m_hoverColor = hoverColor;
    m_textOffset = textOffset;
    m_borderWidth = borderWidth;
    m_borderColor = borderColor;
    m_centerText = centerText;
    m_cornerRadius = cornerRadius;
    m_isDeactivated = isDeactivated;
    m_deactivatedColor = deactivatedColor;


}

bool zl::ButtonStyle::isDeactivated() {
    return m_isDeactivated;
}

zl::fVector zl::ButtonStyle::getSize() {
    return m_size;
}

zl::fVector zl::ButtonStyle::getTextOffset() {
    return m_textOffset;
}

int zl::ButtonStyle::getBorderWidth() {
    return m_borderWidth;
}

int zl::ButtonStyle::getCornerRadius() {
    return m_cornerRadius;
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

bool zl::ButtonStyle::centerText() {
    return m_centerText;
}














