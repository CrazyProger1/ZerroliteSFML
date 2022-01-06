//
// Created by crazy on 04.01.2022.
//

#include "../../include/GUI/Button.h"

void zl::Button::activate() {
    m_isDeactivated = false;
}

void zl::Button::deactivate() {
    m_isDeactivated = true;
}

void zl::Button::draw(sf::RenderTarget &renderTarget) {
    if (m_borderWidth > 0)
        renderTarget.draw(m_borderRect);


    renderTarget.draw(m_mainRect);

    if (isTextSet) {
        m_text.draw(renderTarget);
    }

}

void zl::Button::init() {
    fCoords pos = getPosition();

    m_mainRect.setSize(m_size);
    m_mainRect.setPosition(pos);
    m_mainRect.setFillColor(m_color);

    if (m_borderWidth > 0) {
        m_borderRect.setSize({m_size.x + (float) m_borderWidth * 2, m_size.y + (float) m_borderWidth * 2});
        m_borderRect.setFillColor(m_borderColor);
        m_borderRect.setPosition({pos.x - (float) m_borderWidth, pos.y - (float) m_borderWidth});
    }
    isTextSet = m_text.getText() != "";
    if (isTextSet) {
        centralizeText();
        m_text.initialize();
    }


}

void zl::Button::handleSFMLEvent(sf::Event &event) {
    if (isHovered()) {
        m_mainRect.setFillColor(m_hoverColor);
        if (event.type == sf::Event::MouseButtonPressed) {
            m_isClicked = true;

        }

    } else {
        m_mainRect.setFillColor(m_color);

    }
}

bool zl::Button::isClicked() {
    bool buff = m_isClicked;
    m_isClicked = false;
    return buff;
}

bool zl::Button::isHovered() {
    sf::RenderWindow *window = getParentWindow();
    iCoords mousePos = sf::Mouse::getPosition(*window);


    fCoords pos = getPosition();


    if (mousePos.x > pos.x && mousePos.x < pos.x + m_size.x) {
        if (mousePos.y > pos.y && mousePos.y < pos.y + m_size.y) {
            return true;
        }
    }
    return false;
}

void zl::Button::setSize(const zl::fSize &size) {
    m_size = size;
    init();
}

void zl::Button::setTextOffset(const zl::fSize &offset) {
    m_textOffset = offset;
    init();
}

void zl::Button::setBorderWidth(int width) {
    m_borderWidth = width;
    init();
}

void zl::Button::setCornerRadius(int radius) {
    m_cornerRadius = radius;
    init();
}


void zl::Button::setText(zl::Text &text) {
    m_text = text;
    init();
}

zl::Button::Button(const zl::fSize &size, const zl::RGBAColor &color, const zl::RGBAColor &hoverColor,
                   const zl::Text &text, const zl::fSize &textOffset, int borderWidth, const zl::RGBAColor &borderColor,
                   bool centerText) {
    m_size = size;
    m_color = color;
    m_hoverColor = hoverColor;
    m_text = text;
    m_textOffset = textOffset;
    m_borderWidth = borderWidth;
    m_borderColor = borderColor;
    m_centerText = centerText;
    init();

}

void zl::Button::setBorderColor(const zl::RGBAColor &color) {
    m_borderColor = color;
    init();
}

void zl::Button::setHoverColor(const zl::RGBAColor &color) {
    m_hoverColor = color;
    init();
}

void zl::Button::setCenterText(bool center) {
    m_centerText = center;
    init();
}

void zl::Button::centralizeText() {
    fCoords pos = getPosition();

    if (!m_centerText)
        m_text.setPosition({pos.x + m_textOffset.x, pos.y + m_textOffset.y});
    else {
        fSize textSize = m_text.getFullSize();

        m_text.setPosition(
                {pos.x + m_textOffset.x + m_size.x / 2 - textSize.x / 2,
                 pos.y + m_textOffset.y + m_size.y / 2 - textSize.y / 2});
    }
}

zl::Button::Button() = default;
