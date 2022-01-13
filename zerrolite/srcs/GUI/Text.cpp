//
// Created by crazy on 07.01.2022.
//

#include "../../include/GUI/Text.h"


zl::Text::Text() = default;


zl::Text::Text(const zl::str &text,
               const zl::str &fontFilepath,
               int fontSize,
               unsigned int textSFMLStyle,
               int underlineOffset,
               int underlineWidth,
               const zl::RGBAColor &textColor, const zl::RGBAColor &underlineColor, const zl::RGBAColor &textHoverColor,
               const zl::RGBAColor &underlineHoverColor) {

    m_textString = text;
    m_fontFilepath = fontFilepath;
    m_fontSize = fontSize;
    m_underlineOffset = underlineOffset;
    m_underlineWidth = underlineWidth;
    m_textColor = textColor;
    m_underlineColor = underlineColor;
    m_textHoverColor = textHoverColor;
    m_underlineHoverColor = underlineHoverColor;
    m_textSFMLStyle = textSFMLStyle;

    init();

}

void zl::Text::setText(const zl::str &text) {
    m_textString = text;
    init();
}

void zl::Text::setFont(const zl::str &filepath) {
    m_fontFilepath = filepath;
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

void zl::Text::setTextSFMLStyle(unsigned int style) {
    m_textSFMLStyle = style;
    init();
}

void zl::Text::init() {
    fVector pos = getPosition();

    if (!m_font.loadFromFile(m_fontFilepath)) {
        std::cerr << "File did not found" << std::endl;
        throw std::exception();
    }


    m_text.setFont(m_font);
    m_text.setString(m_textString);
    m_text.setCharacterSize(m_fontSize);
    m_text.setFillColor(m_textColor);
    m_text.setPosition(pos);
    m_text.setStyle(m_textSFMLStyle);


    fVector size = getSize();


    if (m_underlineWidth > 0) {
        m_underlineRect.setSize({size.x, (float) m_underlineWidth});
        m_underlineRect.setPosition({pos.x + 1, pos.y + size.y + m_underlineOffset});
        m_underlineRect.setFillColor(m_underlineColor);
    }

}

void zl::Text::draw(sf::RenderTarget &renderTarget) {
    if (m_underlineWidth > 0)
        renderTarget.draw(m_underlineRect);

    renderTarget.draw(m_text);

}

void zl::Text::handleSFMLEvent(sf::Event &event) {
    checkHover();
    checkClick(event);

    if (m_isHovered) {
        m_text.setFillColor(m_textHoverColor);
        m_underlineRect.setFillColor(m_underlineHoverColor);
    } else {
        m_text.setFillColor(m_textColor);
        m_underlineRect.setFillColor(m_underlineColor);
    }
}

void zl::Text::updateState() {

}


zl::fVector zl::Text::getSize() {
    float width = m_text.getLocalBounds().width;
    float height = m_fontSize;
    return {width, height};
}

zl::fVector zl::Text::getFullSize() {
    float width = m_text.getLocalBounds().width;
    float height = m_fontSize;
    return {width, height + (float) m_underlineWidth + (float) m_underlineOffset};
}


zl::str &zl::Text::getText() {
    return m_textString;
}


zl::RGBAColor &zl::Text::getTextHoverColor() {
    return m_textHoverColor;
}

zl::RGBAColor &zl::Text::getTextColor() {
    return m_textColor;
}

void zl::Text::checkClick(sf::Event &event) {
    if (m_isHovered)
        if (event.type == sf::Event::MouseButtonPressed) {
            m_isClicked = true;
            return;
        }

    m_isClicked = false;
}

void zl::Text::checkHover() {
    sf::RenderWindow *window = getParentWindow();
    fVector size = getFullSize();
    fVector pos = getPosition();
    iVector mousePos = sf::Mouse::getPosition(*window);

    if (mousePos.x > pos.x && mousePos.x < pos.x + size.x)
        if (mousePos.y > pos.y && mousePos.y < pos.y + size.y) {
            m_isHovered = true;
            return;
        }

    m_isHovered = false;
}

bool zl::Text::isHovered() {
    return m_isHovered;
}

bool zl::Text::isClicked() {
    bool buff = m_isClicked;
    m_isClicked = false;
    return buff;
}

void zl::Text::initialize() {
    init();
}

void zl::Text::setStyle(zl::TextStyle &style) {

    m_textColor = style.getTextColor();
    m_underlineColor = style.getUnderlineColor();
    m_textHoverColor = style.getTextHoverColor();
    m_underlineHoverColor = style.getUnderlineHoverColor();
    m_textSFMLStyle = style.getTextSFMLStyle();
    m_underlineWidth = style.getUnderlineWidth();
    m_underlineOffset = style.getUnderlineOffset();
    m_fontSize = style.getFontSize();
    m_fontFilepath = style.getFontFilepath();
    init();
}








