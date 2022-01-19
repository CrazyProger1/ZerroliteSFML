//
// Created by crazy on 14.01.2022.
//

#include "../../include/Styles/CheckBoxStyle.h"

zl::CheckBoxStyle::CheckBoxStyle(const sf::Vector2f &size,
                                 const sf::Vector2f &checkOffset,
                                 int checkScale,
                                 int checkAngle,
                                 const sf::Vector2f &checkHornsLengthCoefficient,
                                 int borderWidth,
                                 const zl::RGBAColor &color,
                                 const zl::RGBAColor &hoverColor,
                                 const zl::RGBAColor &checkColor,
                                 const zl::RGBAColor &colorWhenChecked,
                                 const zl::RGBAColor &borderColor,
                                 bool checked) {
    m_size = size;
    m_checkOffset = checkOffset;
    m_iCheckScale = checkScale;
    m_iCheckAngle = checkAngle;
    m_checkHornsLenCoef = checkHornsLengthCoefficient;
    m_iBorderWidth = borderWidth;
    m_color = color;
    m_hoverColor = hoverColor;
    m_checkColor = checkColor;
    m_colorWhenChecked = colorWhenChecked;
    m_borderColor = borderColor;
    m_bIsChecked = checked;

}

sf::Vector2f &zl::CheckBoxStyle::getSize() {
    return m_size;
}

sf::Vector2f &zl::CheckBoxStyle::getCheckOffset() {
    return m_checkOffset;
}

sf::Vector2f &zl::CheckBoxStyle::getCheckHornsLengthCoefficient() {
    return m_checkHornsLenCoef;
}

int zl::CheckBoxStyle::getCheckScale() const {
    return m_iCheckScale;
}

int zl::CheckBoxStyle::getCheckAngle() const {
    return m_iCheckAngle;
}

zl::RGBAColor &zl::CheckBoxStyle::getColor() {
    return m_color;
}

zl::RGBAColor &zl::CheckBoxStyle::getHoverColor() {
    return m_hoverColor;
}

zl::RGBAColor &zl::CheckBoxStyle::getCheckColor() {
    return m_checkColor;
}

zl::RGBAColor &zl::CheckBoxStyle::getBorderColor() {
    return m_borderColor;
}

zl::RGBAColor &zl::CheckBoxStyle::getColorWhenChecked() {
    return m_colorWhenChecked;
}

int zl::CheckBoxStyle::getBorderWidth() const {
    return m_iBorderWidth;
}


bool zl::CheckBoxStyle::isChecked() const {
    return m_bIsChecked;
}
