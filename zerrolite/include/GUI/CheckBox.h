//
// Created by crazy on 13.01.2022.
//

#ifndef ZERROLITESFML_CHECKBOX_H
#define ZERROLITESFML_CHECKBOX_H

#include "../Core/Entity.h"
#include "../Styles/CheckBoxStyle.h"
#include <string>
#include <utility>
#include <iostream>

namespace zl {
    class CheckBox : public Entity {
    private:
        fVector m_size;
        fVector m_checkOffset = {0, 0};

        int m_checkScale = 1;
        int m_checkAngle = 90;
        float m_checkAngleRatio = 1;
        fVector m_checkHornsLenCoef = {1, 1};

        RGBAColor m_color = {100, 100, 100};
        RGBAColor m_hoverColor = {100, 100, 200};
        RGBAColor m_checkColor = {255, 0, 0};
        RGBAColor m_borderColor = {20, 0, 255};
        RGBAColor m_colorWhenChecked = {100, 255, 100};

        sf::RectangleShape m_mainRect;
        sf::RectangleShape m_borderRect;
        sf::RectangleShape m_checkPart1;
        sf::RectangleShape m_checkPart2;

        int m_borderWidth = 0;
        int m_cornerRadius = 0;


        bool m_isChecked = false;
        bool m_isHovered = false;
        bool m_isClicked = false;

        void init();

        void checkHover();

        void checkClick(sf::Event &event);

    public:
        CheckBox();

        explicit CheckBox(
                const fVector &size,
                int checkScale = 1,
                const RGBAColor &color = {100, 255, 0},
                const RGBAColor &checkColor = {100, 255, 0},
                const RGBAColor &borderColor = {20, 0, 255},
                int borderWidth = 0,
                bool isChecked = false
        );

        void initialize() override;

        void setSize(const fVector &size);

        void setCheckScale(int scale);

        void setColor(const RGBAColor &color);

        void setCheckColor(const RGBAColor &color);

        void setBorderColor(const RGBAColor &color);

        void setColorWhenChecked(const RGBAColor &color);

        void setHoverColor(const RGBAColor &color);

        void setCheckHornsLengthCoefficient(const fVector &coef);

        void setBorderWidth(int width);

        void setCheckAngle(int angle);

        void setChecked(bool checked = false);

        void setCheckOffset(const fVector &offset);

        void setStyle(CheckBoxStyle &style);

        void draw(sf::RenderTarget &rt) override;

        void updateState() override;

        void handleSFMLEvent(sf::Event &event) override;

        bool isClicked();

        bool isHovered();

        bool isChecked();

    };
}


#endif //ZERROLITESFML_CHECKBOX_H
