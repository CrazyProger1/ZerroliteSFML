//
// Created by crazy on 13.01.2022.
//

#include "../../include/GUI/CheckBox.h"


zl::CheckBox::CheckBox() = default;

zl::CheckBox::CheckBox(const zl::fVector &size,
                       int checkScale,
                       const zl::RGBAColor &color,
                       const zl::RGBAColor &checkColor,
                       const zl::RGBAColor &borderColor,
                       int borderWidth,
                       bool checked) {
    m_size = size;
    m_checkScale = checkScale;
    m_color = color;
    m_checkColor = checkColor;
    m_borderColor = borderColor;
    m_borderWidth = borderWidth;
    m_isChecked = checked;

    init();
}

void zl::CheckBox::init() {
    fVector pos = getPosition();

    m_mainRect.setSize(m_size);
    m_mainRect.setPosition(pos);
    m_mainRect.setFillColor(m_color);


    if (m_borderWidth > 0) {
        m_borderRect.setSize({m_size.x + m_borderWidth * 2, m_size.y + m_borderWidth * 2});
        m_borderRect.setPosition({pos.x - m_borderWidth, pos.y - m_borderWidth});
        m_borderRect.setFillColor(m_borderColor);
    }

    m_checkPart1.setSize({m_size.x / 2 * m_checkScale * m_checkHornsLenCoef.x,
                          m_size.y / 8 * m_checkScale});


    m_checkPart2.setSize({m_size.x / 1.1f * m_checkScale * m_checkHornsLenCoef.y,
                          m_size.y / 8});

    m_checkPart1.setOrigin(m_size.x / 2 * m_checkScale * m_checkHornsLenCoef.x,
                           m_size.y / 8 * m_checkScale);

    m_checkPart2.setOrigin({m_size.x / 1.1f * m_checkScale * m_checkHornsLenCoef.y,
                            m_size.y / 8});

    m_checkPart1.setFillColor(m_checkColor);
    m_checkPart2.setFillColor(m_checkColor);

    float angle1 = 50 * m_checkAngleRatio;
    float angle2 = m_checkAngle - angle1;

    m_checkPart1.setRotation(-angle1 + 90);
    m_checkPart2.setRotation(angle2 + 90);

    m_checkPart1.setPosition(pos.x + m_size.x / 2.5f + m_checkOffset.x,
                             pos.y + m_size.y / 1.4f + m_checkOffset.y);

    m_checkPart2.setPosition(pos.x + m_size.x / 2.5f + m_checkOffset.x,
                             pos.y + m_size.y / 1.4f + m_checkOffset.y);


}

void zl::CheckBox::initialize() {
    init();
}

void zl::CheckBox::draw(sf::RenderTarget &rt) {
    if (m_borderWidth > 0)
        rt.draw(m_borderRect);

    rt.draw(m_mainRect);

    if (m_isChecked) {
        rt.draw(m_checkPart1);
        rt.draw(m_checkPart2);
    }


}

void zl::CheckBox::updateState() {
    checkHover();

    if (m_isHovered && !m_isChecked) {
        if (!m_justHovered) {
            m_mainRect.setFillColor(m_hoverColor);
            m_justHovered = true;
        }


    } else if (!m_isHovered && !m_isChecked) {
        if (m_justHovered) {
            m_mainRect.setFillColor(m_color);
            m_justHovered = false;
        }


    }


    if (isClicked()) {
        m_isChecked = !m_isChecked;

        if (m_isChecked) {
            if (!m_justChecked) {
                m_mainRect.setFillColor(m_colorWhenChecked);
                m_justChecked = true;
            }

        } else {
            if (m_justChecked) {
                m_mainRect.setFillColor(m_color);
                m_justChecked = false;
            }

        }
    }

}

void zl::CheckBox::setSize(const zl::fVector &size) {
    m_size = size;
    init();
}

void zl::CheckBox::setCheckScale(int scale) {
    m_checkScale = scale;
    init();
}

void zl::CheckBox::setColor(const zl::RGBAColor &color) {
    m_color = color;
    init();
}

void zl::CheckBox::setCheckColor(const zl::RGBAColor &color) {
    m_checkColor = color;
    init();
}

void zl::CheckBox::setBorderColor(const zl::RGBAColor &color) {
    m_borderColor = color;
    init();
}

void zl::CheckBox::setBorderWidth(int width) {
    m_borderWidth = width;
    init();
}

void zl::CheckBox::setCheckAngle(int angle) {
    m_checkAngle = angle;
    init();
}

void zl::CheckBox::setCheckOffset(const zl::fVector &offset) {
    m_checkOffset = offset;
    init();
}

void zl::CheckBox::setColorWhenChecked(const zl::RGBAColor &color) {
    m_colorWhenChecked = color;
    init();
}

void zl::CheckBox::setHoverColor(const zl::RGBAColor &color) {
    m_hoverColor = color;
    init();
}

void zl::CheckBox::setCheckHornsLengthCoefficient(const zl::fVector &coef) {
    m_checkHornsLenCoef = coef;
    init();
}

void zl::CheckBox::setStyle(zl::CheckBoxStyle &style) {
    m_size = style.getSize();
    m_borderWidth = style.getBorderWidth();
    m_checkScale = style.getCheckScale();
    m_checkOffset = style.getCheckOffset();
    m_color = style.getColor();
    m_hoverColor = style.getHoverColor();
    m_checkColor = style.getCheckColor();
    m_borderColor = style.getBorderColor();
    m_colorWhenChecked = style.getColorWhenChecked();
    m_checkAngle = style.getCheckAngle();
    m_checkHornsLenCoef = style.getCheckHornsLengthCoefficient();
    m_isChecked = style.isChecked();
    init();
}

void zl::CheckBox::setChecked(bool checked) {
    m_isChecked = checked;
}


void zl::CheckBox::checkHover() {
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

void zl::CheckBox::checkClick(sf::Event &event) {
    if (m_isHovered)
        if (event.type == sf::Event::MouseButtonPressed) {
            m_isClicked = true;
            return;
        }

    m_isClicked = false;
}

void zl::CheckBox::handleSFMLEvent(sf::Event &event) {
    checkClick(event);
}

bool zl::CheckBox::isClicked() {
    bool buff = m_isClicked;
    m_isClicked = false;
    return buff;
}

bool zl::CheckBox::isHovered() {
    return m_isHovered;
}

bool zl::CheckBox::isChecked() {
    return m_isChecked;
}







