//
// Created by crazy on 12.01.2022.
//

#include "../../include/Styles/TextStyle.h"

zl::TextStyle::TextStyle(const zl::str &fontFilepath, int textSFMLStyle, int fontSize, int underlineOffset,
                         int underlineWidth, const zl::RGBAColor &textColor, const zl::RGBAColor &underlineColor,
                         const zl::RGBAColor &textHoverColor, const zl::RGBAColor &underlineHoverColor) {
    m_fontFilepath = fontFilepath;
    m_textSFMLStyle = textSFMLStyle;
    m_fontSize = fontSize;
    m_underlineOffset = underlineOffset;
    m_underlineWidth = underlineWidth;
    m_textColor = textColor;
    m_underlineColor = underlineColor;
    m_textHoverColor = textHoverColor;
    m_underlineHoverColor = underlineHoverColor;
}

zl::str zl::TextStyle::getFontFilepath() {
    return m_fontFilepath;
}

unsigned int zl::TextStyle::getTextSFMLStyle() {
    return m_textSFMLStyle;
}

int zl::TextStyle::getFontSize() {
    return m_fontSize;
}

int zl::TextStyle::getUnderlineOffset() {
    return m_underlineOffset;
}

int zl::TextStyle::getUnderlineWidth() {
    return m_underlineWidth;
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
