//
// Created by crazy on 07.01.2022.
//

#include "../../include/GUI/Text.h"


zl::Text::Text() = default;


zl::Text::Text(
        const zl::TStr &text,
        const zl::TStr &fontFilepath,
        int fontSize,
        unsigned int textSFMLStyle,
        int underlineOffset,
        int underlineWidth,
        const zl::RGBAColor &textColor, const zl::RGBAColor &underlineColor, const zl::RGBAColor &textHoverColor,
        const zl::RGBAColor &underlineHoverColor
) {

    m_sText = text;
    m_sFontFilepath = fontFilepath;
    m_iFontSize = fontSize;
    m_iUnderlineOffset = underlineOffset;
    m_iUnderlineWidth = underlineWidth;
    m_textColor = textColor;
    m_underlineColor = underlineColor;
    m_textHoverColor = textHoverColor;
    m_underlineHoverColor = underlineHoverColor;
    m_uTextSFMLStyle = textSFMLStyle;


}

void zl::Text::checkClick(sf::Event &event) {
    if (m_bIsHovered)
        if (event.type == sf::Event::MouseButtonPressed) {
            m_bIsClicked = true;
            return;
        }

    m_bIsClicked = false;
}

void zl::Text::checkHover() {
    sf::RenderWindow *window = getParentWindow();
    sf::Vector2f size = getFullSize();
    sf::Vector2f pos = getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (mousePos.x > pos.x && mousePos.x < pos.x + size.x)
        if (mousePos.y > pos.y && mousePos.y < pos.y + size.y) {
            m_bIsHovered = true;
            return;
        }

    m_bIsHovered = false;
}


void zl::Text::initialize() {
    setType("text");

    sf::Vector2f pos = getPosition();

    if (!m_font.loadFromFile(m_sFontFilepath)) {
        std::cerr << "File did not found" << std::endl;
        throw std::exception();
    }


    m_text.setFont(m_font);
    m_text.setString(m_sText);
    m_text.setCharacterSize(m_iFontSize);
    m_text.setFillColor(m_textColor);
    m_text.setPosition(pos);
    m_text.setStyle(m_uTextSFMLStyle);

    sf::Vector2f size = getSize();


    if (m_iUnderlineWidth > 0) {
        m_underlineRect.setSize({size.x, (float) m_iUnderlineWidth});
        m_underlineRect.setPosition({pos.x + 1, pos.y + size.y + m_iUnderlineOffset});
        m_underlineRect.setFillColor(m_underlineColor);
    }
}

void zl::Text::setText(const zl::TStr &text) {
    if (m_sText == text)
        return;

    m_sText = text;
    initialize();
}

void zl::Text::setFont(const zl::TStr &filepath) {
    m_sFontFilepath = filepath;
    initialize();
}

void zl::Text::setFontSize(int size) {
    m_iFontSize = size;
    initialize();
}

void zl::Text::setUnderlineOffset(int offset) {
    m_iUnderlineOffset = offset;
    initialize();
}

void zl::Text::setUnderlineWidth(int width) {
    m_iUnderlineWidth = width;
    initialize();
}

void zl::Text::setTextColor(const zl::RGBAColor &color) {
    m_textColor = color;
    initialize();
}

void zl::Text::setUnderlineColor(const zl::RGBAColor &color) {
    m_underlineColor = color;
    initialize();
}

void zl::Text::setTextHoverColor(const zl::RGBAColor &color) {
    m_textHoverColor = color;
    initialize();
}

void zl::Text::setUnderlineHoverColor(const zl::RGBAColor &color) {
    m_underlineHoverColor = color;
    initialize();
}

void zl::Text::setTextSFMLStyle(unsigned int style) {
    m_uTextSFMLStyle = style;
    initialize();
}

void zl::Text::setStyle(zl::TextStyle &style) {

    m_textColor = style.getTextColor();
    m_underlineColor = style.getUnderlineColor();
    m_textHoverColor = style.getTextHoverColor();
    m_underlineHoverColor = style.getUnderlineHoverColor();
    m_uTextSFMLStyle = style.getTextSFMLStyle();
    m_iUnderlineWidth = style.getUnderlineWidth();
    m_iUnderlineOffset = style.getUnderlineOffset();
    m_iFontSize = style.getFontSize();
    m_sFontFilepath = style.getFontFilepath();
    initialize();
}


sf::Vector2f zl::Text::getSize() {
    float width = m_text.getLocalBounds().width;
    float height = m_iFontSize;
    return {width, height};
}

sf::Vector2f zl::Text::getFullSize() {
    float width = m_text.getLocalBounds().width;
    float height = m_iFontSize;
    return {width, height + (float) m_iUnderlineWidth + (float) m_iUnderlineOffset};
}


zl::TStr &zl::Text::getText() {
    return m_sText;
}


zl::RGBAColor &zl::Text::getTextHoverColor() {
    return m_textHoverColor;
}

zl::RGBAColor &zl::Text::getTextColor() {
    return m_textColor;
}


bool zl::Text::isHovered() {
    return m_bIsHovered;
}

bool zl::Text::isClicked() {
    bool buff = m_bIsClicked;
    m_bIsClicked = false;
    return buff;
}


void zl::Text::draw(sf::RenderTarget &renderTarget) {
    if (m_iUnderlineWidth > 0)
        renderTarget.draw(m_underlineRect);

    renderTarget.draw(m_text);

}

void zl::Text::handleSFMLEvent(sf::Event &event) {
    checkClick(event);


}

void zl::Text::updateState() {
    checkHover();

    if (m_bIsHovered) {
        if (!m_bJustHovered) {
            m_text.setFillColor(m_textHoverColor);
            m_underlineRect.setFillColor(m_underlineHoverColor);
            m_bJustHovered = true;
        }

    } else {
        if (m_bJustHovered) {
            m_text.setFillColor(m_textColor);
            m_underlineRect.setFillColor(m_underlineColor);
            m_bJustHovered = false;
        }

    }
}















