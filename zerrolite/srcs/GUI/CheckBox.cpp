//
// Created by crazy on 13.01.2022.
//

#include "../../include/GUI/CheckBox.h"


zl::CheckBox::CheckBox() = default;

zl::CheckBox::CheckBox(const sf::Vector2f &size,
                       int checkScale,
                       const zl::RGBAColor &color,
                       const zl::RGBAColor &checkColor,
                       const zl::RGBAColor &borderColor,
                       int borderWidth,
                       bool checked) {
    m_size = size;
    m_iCheckScale = checkScale;
    m_color = color;
    m_checkColor = checkColor;
    m_borderColor = borderColor;
    m_iBorderWidth = borderWidth;
    m_bIsChecked = checked;

}

void zl::CheckBox::checkHover() {
    sf::RenderWindow *window = getParentWindow();
    sf::Vector2f pos = getPosition();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (mousePos.x > pos.x && mousePos.x < pos.x + m_size.x)
        if (mousePos.y > pos.y && mousePos.y < pos.y + m_size.y) {
            m_bIsHovered = true;
            return;
        }

    m_bIsHovered = false;
}

void zl::CheckBox::checkClick(sf::Event &event) {
    if (m_bIsHovered)
        if (event.type == sf::Event::MouseButtonPressed) {
            m_bIsClicked = true;
            return;
        }

    m_bIsClicked = false;
}


void zl::CheckBox::initialize() {
    setType("checkbox");

    sf::Vector2f pos = getPosition();

    m_mainRect.setSize(m_size);
    m_mainRect.setPosition(pos);
    m_mainRect.setFillColor(m_color);


    if (m_iBorderWidth > 0) {
        m_borderRect.setSize({m_size.x + m_iBorderWidth * 2, m_size.y + m_iBorderWidth * 2});
        m_borderRect.setPosition({pos.x - m_iBorderWidth, pos.y - m_iBorderWidth});
        m_borderRect.setFillColor(m_borderColor);
    }

    m_checkPart1.setSize({m_size.x / 2 * m_iCheckScale * m_checkHornsLenCoef.x,
                          m_size.y / 8 * m_iCheckScale});


    m_checkPart2.setSize({m_size.x / 1.1f * m_iCheckScale * m_checkHornsLenCoef.y,
                          m_size.y / 8});

    m_checkPart1.setOrigin(m_size.x / 2 * m_iCheckScale * m_checkHornsLenCoef.x,
                           m_size.y / 8 * m_iCheckScale);

    m_checkPart2.setOrigin({m_size.x / 1.1f * m_iCheckScale * m_checkHornsLenCoef.y,
                            m_size.y / 8});

    m_checkPart1.setFillColor(m_checkColor);
    m_checkPart2.setFillColor(m_checkColor);

    float angle1 = 50 * m_fltCheckAngleRatio;
    float angle2 = m_iCheckAngle - angle1;

    m_checkPart1.setRotation(-angle1 + 90);
    m_checkPart2.setRotation(angle2 + 90);

    m_checkPart1.setPosition(pos.x + m_size.x / 2.5f + m_checkOffset.x,
                             pos.y + m_size.y / 1.4f + m_checkOffset.y);

    m_checkPart2.setPosition(pos.x + m_size.x / 2.5f + m_checkOffset.x,
                             pos.y + m_size.y / 1.4f + m_checkOffset.y);
}


void zl::CheckBox::setSize(const sf::Vector2f &size) {
    m_size = size;
    initialize();
}

void zl::CheckBox::setCheckScale(int scale) {
    m_iCheckScale = scale;
    initialize();
}

void zl::CheckBox::setColor(const zl::RGBAColor &color) {
    m_color = color;
    initialize();
}

void zl::CheckBox::setCheckColor(const zl::RGBAColor &color) {
    m_checkColor = color;
    initialize();
}

void zl::CheckBox::setBorderColor(const zl::RGBAColor &color) {
    m_borderColor = color;
    initialize();
}

void zl::CheckBox::setBorderWidth(int width) {
    m_iBorderWidth = width;
    initialize();
}

void zl::CheckBox::setCheckAngle(int angle) {
    m_iCheckAngle = angle;
    initialize();
}

void zl::CheckBox::setCheckOffset(const sf::Vector2f &offset) {
    m_checkOffset = offset;
    initialize();
}

void zl::CheckBox::setColorWhenChecked(const zl::RGBAColor &color) {
    m_colorWhenChecked = color;
    initialize();
}

void zl::CheckBox::setHoverColor(const zl::RGBAColor &color) {
    m_hoverColor = color;
    initialize();
}

void zl::CheckBox::setCheckHornsLengthCoefficient(const sf::Vector2f &coef) {
    m_checkHornsLenCoef = coef;
    initialize();
}

void zl::CheckBox::setStyle(zl::CheckBoxStyle &style) {
    m_size = style.getSize();
    m_iBorderWidth = style.getBorderWidth();
    m_iCheckScale = style.getCheckScale();
    m_checkOffset = style.getCheckOffset();
    m_color = style.getColor();
    m_hoverColor = style.getHoverColor();
    m_checkColor = style.getCheckColor();
    m_borderColor = style.getBorderColor();
    m_colorWhenChecked = style.getColorWhenChecked();
    m_iCheckAngle = style.getCheckAngle();
    m_checkHornsLenCoef = style.getCheckHornsLengthCoefficient();
    m_bIsChecked = style.isChecked();
    initialize();
}

void zl::CheckBox::setChecked(bool checked) {
    m_bIsChecked = checked;
}

void zl::CheckBox::draw(sf::RenderTarget &rt) {
    if (m_iBorderWidth > 0)
        rt.draw(m_borderRect);

    rt.draw(m_mainRect);

    if (m_bIsChecked) {
        rt.draw(m_checkPart1);
        rt.draw(m_checkPart2);
    }


}

bool zl::CheckBox::isClicked() {
    bool buff = m_bIsClicked;
    m_bIsClicked = false;
    return buff;
}

bool zl::CheckBox::isHovered() const {
    return m_bIsHovered;
}

bool zl::CheckBox::isChecked() const {
    return m_bIsChecked;
}


void zl::CheckBox::updateState() {
    checkHover();

    if (m_bIsHovered && !m_bIsChecked) {
        if (!m_bJustHovered) {
            m_mainRect.setFillColor(m_hoverColor);
            m_bJustHovered = true;
        }


    } else if (!m_bIsHovered && !m_bIsChecked) {
        if (m_bJustHovered) {
            m_mainRect.setFillColor(m_color);
            m_bJustHovered = false;
        }


    }


    if (isClicked()) {
        m_bIsChecked = !m_bIsChecked;

        if (m_bIsChecked) {
            if (!m_bJustChecked) {
                m_mainRect.setFillColor(m_colorWhenChecked);
                m_bJustChecked = true;
            }

        } else {
            if (m_bJustChecked) {
                m_mainRect.setFillColor(m_color);
                m_bJustChecked = false;
            }
        }
    }

}


void zl::CheckBox::handleSFMLEvent(sf::Event &event) {
    checkClick(event);
}








