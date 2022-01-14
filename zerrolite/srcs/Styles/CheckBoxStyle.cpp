//
// Created by crazy on 14.01.2022.
//

#include "../../include/Styles/CheckBoxStyle.h"

zl::CheckBoxStyle::CheckBoxStyle(const zl::fVector &size,
                                 const zl::fVector &checkOffset,
                                 int checkScale,
                                 int checkAngle,
                                 const zl::fVector &checkHornsLengthCoefficient,
                                 int borderWidth,
                                 const zl::RGBAColor &color,
                                 const zl::RGBAColor &hoverColor,
                                 const zl::RGBAColor &checkColor,
                                 const zl::RGBAColor &colorWhenChecked,
                                 const zl::RGBAColor &borderColor,
                                 bool checked) {
    m_size = size;
    m_checkOffset = checkOffset;
    m_checkScale = checkScale;
    m_checkAngle = checkAngle;
    m_checkHornsLenCoef = checkHornsLengthCoefficient;
    m_borderWidth = borderWidth;
    m_color = color;
    m_hoverColor = hoverColor;
    m_checkColor = checkColor;
    m_colorWhenChecked = colorWhenChecked;
    m_borderColor = borderColor;
    m_isChecked = checked;

}

zl::fVector zl::CheckBoxStyle::getSize() {
    return m_size;
}

zl::fVector zl::CheckBoxStyle::getCheckOffset() {
    return m_checkOffset;
}

zl::fVector zl::CheckBoxStyle::getCheckHornsLengthCoefficient() {
    return m_checkHornsLenCoef;
}

int zl::CheckBoxStyle::getCheckScale() {
    return m_checkScale;
}

int zl::CheckBoxStyle::getCheckAngle() {
    return m_checkAngle;
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

int zl::CheckBoxStyle::getBorderWidth() {
    return m_borderWidth;
}

bool zl::CheckBoxStyle::isChecked() {
    return m_isChecked;
}
