//
// Created by crazy on 05.01.2022.
//

#include "../../include/GUI/Text.h"


zl::Text::Text() = default;


zl::Text::Text(const zl::str &text, const zl::str &font, int fontSize, int underlineOffset, int underlineWidth,
               const zl::RGBAColor &textColor, const zl::RGBAColor &underlineColor, const zl::RGBAColor &textHoverColor,
               const zl::RGBAColor &underlineHoverColor) {
    m_text = text;
    m_font = font;
    m_fontSize = fontSize;
    m_underlineOffset = underlineOffset;
    m_underlineWidth = underlineWidth;
    m_textColor = textColor;
    m_underlineColor = underlineColor;
    m_textHoverColor = textHoverColor;
    m_underlineHoverColor = underlineHoverColor;
    init();

}

void zl::Text::setText(const zl::str &text) {
    m_text = text;
    init();
}

void zl::Text::setFont(const zl::str &font) {
    m_font = font;
    init();
}

void zl::Text::setFontSize(int size) {
    m_fontSize = size;
    init();
}

void zl::Text::setUnderlineOffset(int offset) {
    m_underlineOffset = offset;
    init();
}

void zl::Text::setUnderlineWidth(int width) {
    m_underlineWidth = width;
    init();
}

void zl::Text::setTextColor(const zl::RGBAColor &color) {
    m_textColor = color;
    init();
}

void zl::Text::setUnderlineColor(const zl::RGBAColor &color) {
    m_underlineColor = color;
    init();
}

void zl::Text::setTextHoverColor(const zl::RGBAColor &color) {
    m_textHoverColor = color;
    init();
}

void zl::Text::setUnderlineHoverColor(const zl::RGBAColor &color) {
    m_underlineHoverColor = color;
    init();
}

void zl::Text::draw(sf::RenderTarget &renderTarget) {
    if (m_underlineWidth != 0) {
        renderTarget.draw(m_underlineRect);
    }
    renderTarget.draw(m_sf_text);

}

void zl::Text::init() {

    if (!m_sf_font.loadFromFile(m_font)) {
        throw std::exception();
    }

    m_sf_text.setFont(m_sf_font);
    m_sf_text.setString(m_text);
    m_sf_text.setCharacterSize(m_fontSize);
    m_sf_text.setFillColor(m_textColor);
    m_sf_text.setPosition(getPosition());

    fSize size = getTextSize();
    fCoords pos = getPosition();

    if (m_underlineWidth > 0) {
        m_underlineRect.setSize({size.x, (float) m_underlineWidth});
        m_underlineRect.setPosition({pos.x, pos.y + size.y + m_underlineOffset});
        m_underlineRect.setFillColor(m_underlineColor);
    }

}


void zl::Text::handleSFMLEvent(sf::Event &event) {

    if (isHovered()) {
        m_sf_text.setFillColor(m_textHoverColor);
        m_underlineRect.setFillColor(m_underlineHoverColor);
        if (event.type == sf::Event::MouseButtonPressed) {
            m_isClicked = true;

        }

    } else {
        m_sf_text.setFillColor(m_textColor);
        m_underlineRect.setFillColor(m_underlineColor);

    }

}

bool zl::Text::isHovered() {
    sf::RenderWindow *window = getParentWindow();
    iCoords mousePos = sf::Mouse::getPosition(*window);

    fSize size = getFullSize();
    fCoords pos = getPosition();


    if (mousePos.x > pos.x && mousePos.x < pos.x + size.x) {
        if (mousePos.y > pos.y && mousePos.y < pos.y + size.y) {
            return true;
        }
    }
    return false;
}

zl::fSize zl::Text::getTextSize() {
    float width = m_sf_text.getLocalBounds().width;
    float height = m_fontSize;
    return {width, height};
}

zl::fSize zl::Text::getFullSize() {
    float width = m_sf_text.getLocalBounds().width;
    float height = m_fontSize;
    return {width, height + (float) m_underlineWidth + (float) m_underlineOffset};
}

bool zl::Text::isClicked() {
    bool buff = m_isClicked;
    m_isClicked = false;
    return buff;
}

zl::str zl::Text::getText() {
    return m_text;
}

void zl::Text::initialize() {
    init();
}







