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
        sf::Vector2f m_size;
        sf::Vector2f m_checkOffset = {0, 0};

        int m_iCheckScale = 1;
        int m_iCheckAngle = 90;
        float m_fltCheckAngleRatio = 1;
        sf::Vector2f m_checkHornsLenCoef = {1, 1};

        RGBAColor m_color = {100, 100, 100};
        RGBAColor m_hoverColor = {100, 100, 200};
        RGBAColor m_checkColor = {255, 0, 0};
        RGBAColor m_borderColor = {20, 0, 255};
        RGBAColor m_colorWhenChecked = {100, 255, 100};

        sf::RectangleShape m_mainRect;
        sf::RectangleShape m_borderRect;
        sf::RectangleShape m_checkPart1;
        sf::RectangleShape m_checkPart2;

        int m_iBorderWidth = 0;
//        int m_iCornerRadius = 0;


        bool m_bIsChecked = false;
        bool m_bIsHovered = false;
        bool m_bIsClicked = false;

        bool m_bJustHovered = false; // for optimization
        bool m_bJustChecked = false; // for optimization

        void checkHover();
        /////////////////////////////
        /// This method check if cursor is hovered above checkbox.
        /////////////////////////////

        void checkClick(sf::Event &event);
        /////////////////////////////
        /// This method check if checkbox was clicked.
        /////////////////////////////

    public:
        CheckBox();

        explicit CheckBox(
                const sf::Vector2f &size,
                int checkScale = 1,
                const RGBAColor &color = {100, 255, 0},
                const RGBAColor &checkColor = {100, 255, 0},
                const RGBAColor &borderColor = {20, 0, 255},
                int borderWidth = 0,
                bool isChecked = false
        );

        void initialize() override;


        void setSize(const sf::Vector2f &size);

        void setCheckScale(int scale);

        void setColor(const RGBAColor &color);

        void setCheckColor(const RGBAColor &color);

        void setBorderColor(const RGBAColor &color);

        void setColorWhenChecked(const RGBAColor &color);

        void setHoverColor(const RGBAColor &color);

        void setCheckHornsLengthCoefficient(const sf::Vector2f &coef);

        void setBorderWidth(int width);

        void setCheckAngle(int angle);

        void setChecked(bool checked = false);

        void setCheckOffset(const sf::Vector2f &offset);

        void setStyle(CheckBoxStyle &style);


        bool isClicked();

        bool isHovered() const;

        bool isChecked() const;


        void draw(sf::RenderTarget &rt) override;

        void updateState() override;

        void handleSFMLEvent(sf::Event &event) override;


    };
}


#endif //ZERROLITESFML_CHECKBOX_H
