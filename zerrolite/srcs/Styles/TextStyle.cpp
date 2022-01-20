//
// Created by crazy on 12.01.2022.
//

#include "../../include/Styles/TextStyle.h"

zl::TextStyle::TextStyle(const zl::TStr &fontFilepath, int textSFMLStyle, int fontSize, int underlineOffset,
                         int underlineWidth, const zl::RGBAColor &textColor, const zl::RGBAColor &underlineColor,
                         const zl::RGBAColor &textHoverColor, const zl::RGBAColor &underlineHoverColor) {
    m_sFontFilepath = fontFilepath;
    m_uTextSFMLStyle = textSFMLStyle;
    m_iFontSize = fontSize;
    m_iUnderlineOffset = underlineOffset;
    m_iUnderlineWidth = underlineWidth;
    m_textColor = textColor;
    m_underlineColor = underlineColor;
    m_textHoverColor = textHoverColor;
    m_underlineHoverColor = underlineHoverColor;
}

zl::TStr &zl::TextStyle::getFontFilepath() {
    return m_sFontFilepath;
}

unsigned int zl::TextStyle::getTextSFMLStyle() const {
    return m_uTextSFMLStyle;
}

int zl::TextStyle::getFontSize() const {
    return m_iFontSize;
}

int zl::TextStyle::getUnderlineOffset() const {
    return m_iUnderlineOffset;
}

int zl::TextStyle::getUnderlineWidth() const {
    return m_iUnderlineWidth;
}

zl::RGBAColor &zl::TextStyle::getTextColor() {
    return m_textColor;
}

zl::RGBAColor &zl::TextStyle::getTextHoverColor() {
    return m_textHoverColor;
}

zl::RGBAColor &zl::TextStyle::getUnderlineColor() {
    return m_underlineColor;
}

zl::RGBAColor &zl::TextStyle::getUnderlineHoverColor() {
    return m_underlineHoverColor;
}
