//
// Created by crazy on 07.01.2022.
//

#include "../../include/GUI/Button.h"

zl::Button::Button() = default;

zl::Button::Button(const zl::fVector &size,
                   const zl::RGBAColor &color,
                   const zl::RGBAColor &hoverColor,
                   zl::Text *text,
                   const zl::fVector &textOffset,
                   int borderWidth,
                   const zl::RGBAColor &borderColor,
                   bool centerText,
                   int cornerRadius) {

    m_size = size;
    m_color = color;
    m_hoverColor = hoverColor;
    if (text != nullptr) {
        m_text = *text;
        m_isTextSet = true;
    }
    m_textOffset = textOffset;
    m_borderWidth = borderWidth;
    m_borderColor = borderColor;
    m_centerText = centerText;
    m_cornerRadius = cornerRadius;
    init();
}

void zl::Button::init() {
    fVector pos = getPosition();

    m_mainRect.setSize(m_size);
    m_mainRect.setPosition(pos);

    if (!m_isDeactivated)
        m_mainRect.setFillColor(m_color);
    else
        m_mainRect.setFillColor(m_deactivatedColor);

    if (m_cornerRadius > 0) {

        m_mainRect.setPosition({pos.x + m_cornerRadius, pos.y});
        m_mainRect.setSize({m_size.x - m_cornerRadius * 2, m_size.y});

        m_cornerCircle.setRadius(m_cornerRadius);

        m_sideRect.setSize({(float) m_cornerRadius, m_size.y - m_cornerRadius * 2});

        if (!m_isDeactivated) {
            m_cornerCircle.setFillColor(m_color);
            m_sideRect.setFillColor(m_color);
            m_sideRect.setFillColor(m_color);
        } else {
            m_cornerCircle.setFillColor(m_deactivatedColor);
            m_sideRect.setFillColor(m_deactivatedColor);
            m_sideRect.setFillColor(m_deactivatedColor);
        }
    }

    if (m_borderWidth > 0 && m_cornerRadius == 0) {
        m_borderRect.setSize({m_size.x + (float) m_borderWidth * 2, m_size.y + (float) m_borderWidth * 2});
        m_borderRect.setFillColor(m_borderColor);
        m_borderRect.setPosition({pos.x - (float) m_borderWidth, pos.y - (float) m_borderWidth});

    } else if (m_borderWidth > 0 && m_cornerRadius > 0) {
        m_borderRect.setSize({m_size.x + (float) m_borderWidth * 2 - m_cornerRadius * 2,
                              m_size.y + (float) m_borderWidth * 2});
        m_borderRect.setFillColor(m_borderColor);
        m_borderRect.setPosition({pos.x - (float) m_borderWidth + m_cornerRadius,
                                  pos.y - (float) m_borderWidth});

        m_sideBorderRect.setSize({m_size.x + m_borderWidth * 2,
                                  m_size.y - m_cornerRadius * 2 + m_borderWidth * 2});
        m_sideBorderRect.setPosition({pos.x - m_borderWidth, pos.y + m_cornerRadius - m_borderWidth});
        m_sideBorderRect.setFillColor(m_borderColor);

        m_cornerBorderCircle.setFillColor(m_borderColor);
        m_cornerBorderCircle.setRadius(m_cornerRadius);
    }

    if (m_isTextSet) {
        centralizeText();

        m_text.initialize();

    }
}

void zl::Button::initialize() {
    init();
}

void zl::Button::centralizeText() {
    fVector pos = getPosition();

    if (!m_centerText)
        m_text.setPosition({pos.x + m_textOffset.x, pos.y + m_textOffset.y});
    else {
        fVector textSize = m_text.getFullSize();

        m_text.setPosition(
                {pos.x + m_textOffset.x + m_size.x / 2 - textSize.x / 2,
                 pos.y + m_textOffset.y + m_size.y / 2 - textSize.y / 2});
    }
}

void zl::Button::activate() {
    m_isDeactivated = false;
    init();
}

void zl::Button::deactivate() {
    m_isDeactivated = true;
    init();
}


void zl::Button::setSize(const zl::fVector &size) {
    m_size = size;
    init();
}

void zl::Button::setTextOffset(const zl::fVector &offset) {
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
    m_textColor = text.getTextColor();
    m_textHoverColor = text.getTextHoverColor();
    m_isTextSet = true;
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

void zl::Button::setCenteringText(bool center) {
    m_centerText = center;
    init();
}

void zl::Button::setColor(const zl::RGBAColor &color) {
    m_color = color;
    init();
}

void zl::Button::setDeactivatedColor(const zl::RGBAColor &color) {
    m_deactivatedColor = color;
    init();
}

bool zl::Button::isHovered() {
    return m_isHovered;
}

bool zl::Button::isClicked() {
    bool buff = m_isClicked;
    m_isClicked = false;
    return buff;
}

void zl::Button::draw(sf::RenderTarget &rt) {
    drawBorder(rt);

    rt.draw(m_mainRect);

    if (m_cornerRadius > 0) {
        fVector pos = getPosition();

        m_cornerCircle.setPosition({pos.x, pos.y});
        rt.draw(m_cornerCircle);

        m_cornerCircle.setPosition({pos.x + m_size.x - m_cornerRadius * 2, pos.y});
        rt.draw(m_cornerCircle);

        m_cornerCircle.setPosition({pos.x, pos.y + m_size.y - m_cornerRadius * 2});
        rt.draw(m_cornerCircle);

        m_cornerCircle.setPosition({pos.x + m_size.x - m_cornerRadius * 2, pos.y + m_size.y - m_cornerRadius * 2});
        rt.draw(m_cornerCircle);

        m_sideRect.setPosition({pos.x, pos.y + m_cornerRadius});
        rt.draw(m_sideRect);

        m_sideRect.setPosition({pos.x + m_size.x - m_cornerRadius, pos.y + m_cornerRadius});
        rt.draw(m_sideRect);

    }

    if (m_isTextSet) {
        m_text.draw(rt);
    }


}

void zl::Button::handleSFMLEvent(sf::Event &event) {

    checkClick(event);


}

void zl::Button::updateState() {
    checkHover();

    if (!m_isDeactivated) {
        if (m_isHovered) {
            if (m_isTextSet)
                m_text.setTextColor(m_textHoverColor);

            m_mainRect.setFillColor(m_hoverColor);

            if (m_cornerRadius > 0) {
                m_cornerCircle.setFillColor(m_hoverColor);
                m_sideRect.setFillColor(m_hoverColor);

            }

        } else {
            if (m_isTextSet)
                m_text.setTextColor(m_textColor);

            m_mainRect.setFillColor(m_color);

            if (m_cornerRadius > 0) {
                m_cornerCircle.setFillColor(m_color);
                m_sideRect.setFillColor(m_color);
            }
        }
    }
}

void zl::Button::checkClick(sf::Event &event) {
    if (m_isDeactivated) {
        m_isClicked = false;
        return;
    }

    if (m_isHovered)
        if (event.type == sf::Event::MouseButtonPressed) {
            m_isClicked = true;
            return;
        }

    m_isClicked = false;
}

void zl::Button::checkHover() {
    sf::RenderWindow *window = getParentWindow();
    fVector pos = getPosition();
    iVector mousePos = sf::Mouse::getPosition(*window);

    if (mousePos.x > pos.x && mousePos.x < pos.x + m_size.x)
        if (mousePos.y > pos.y && mousePos.y < pos.y + m_size.y) {
            m_isHovered = true;
            return;
        }

    m_isHovered = false;
}

void zl::Button::drawBorder(sf::RenderTarget &rt) {
    if (m_borderWidth > 0) {
        fVector pos = getPosition();

        rt.draw(m_borderRect);

        if (m_cornerRadius) {
            rt.draw(m_sideBorderRect);

            m_cornerBorderCircle.setPosition({pos.x - m_borderWidth, pos.y - m_borderWidth});
            rt.draw(m_cornerBorderCircle);

            m_cornerBorderCircle.setPosition({pos.x + m_size.x - m_cornerRadius * 2 + m_borderWidth,
                                              pos.y - m_borderWidth});
            rt.draw(m_cornerBorderCircle);

            m_cornerBorderCircle.setPosition(
                    {pos.x - m_borderWidth, pos.y + m_size.y - m_cornerRadius * 2 + m_borderWidth});
            rt.draw(m_cornerBorderCircle);

            m_cornerBorderCircle.setPosition(
                    {pos.x + m_size.x - m_cornerRadius * 2 + m_borderWidth,
                     pos.y + m_size.y - m_cornerRadius * 2 + m_borderWidth});
            rt.draw(m_cornerBorderCircle);
        }
    }


}

void zl::Button::setStyle(zl::ButtonStyle &buttonStyle) {
    m_size = buttonStyle.getSize();
    m_borderWidth = buttonStyle.getBorderWidth();
    m_cornerRadius = buttonStyle.getCornerRadius();
    m_color = buttonStyle.getColor();
    m_borderColor = buttonStyle.getBorderColor();
    m_isDeactivated = buttonStyle.isDeactivated();
    m_textOffset = buttonStyle.getTextOffset();
    m_hoverColor = buttonStyle.getHoverColor();
    m_deactivatedColor = buttonStyle.getDeactivatedColor();
    m_centerText = buttonStyle.centerText();
    init();
}

