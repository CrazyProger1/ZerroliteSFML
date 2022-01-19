//
// Created by crazy on 14.01.2022.
//

#ifndef ZERROLITESFML_CHECKBOXSTYLE_H
#define ZERROLITESFML_CHECKBOXSTYLE_H

#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    struct CheckBoxStyle {
    private:
        sf::Vector2f m_size;
        sf::Vector2f m_checkOffset = {0, 0};
        sf::Vector2f m_checkHornsLenCoef = {1, 1};

        int m_iCheckScale = 1;
        int m_iCheckAngle = 90;
        float m_iCheckAngleRatio = 1;


        RGBAColor m_color = {100, 100, 100};
        RGBAColor m_hoverColor = {100, 100, 200};
        RGBAColor m_checkColor = {255, 0, 0};
        RGBAColor m_borderColor = {20, 0, 255};
        RGBAColor m_colorWhenChecked = {100, 255, 100};

        int m_iBorderWidth = 0;

        bool m_bIsChecked = false;

        //int m_iCornerRadius = 0;
    public:
        explicit CheckBoxStyle(
                const sf::Vector2f &size,
                const sf::Vector2f &checkOffset = {0, 0},
                int checkScale = 1,
                int checkAngle = 90,
                const sf::Vector2f &checkHornsLengthCoefficient = {0, 0},
                int borderWidth = 0,
                const RGBAColor &color = {100, 100, 100},
                const RGBAColor &hoverColor = {100, 100, 100},
                const RGBAColor &checkColor = {255, 0, 0},
                const RGBAColor &colorWhenChecked = {100, 255, 100},
                const RGBAColor &borderColor = {100, 255, 100},
                bool checked = false
        );

        sf::Vector2f &getSize();

        sf::Vector2f &getCheckOffset();

        sf::Vector2f &getCheckHornsLengthCoefficient();

        [[nodiscard]] int getCheckScale() const;

        [[nodiscard]] int getCheckAngle() const;

        RGBAColor &getColor();

        RGBAColor &getHoverColor();

        RGBAColor &getCheckColor();

        RGBAColor &getBorderColor();

        RGBAColor &getColorWhenChecked();

        [[nodiscard]] int getBorderWidth() const;


        [[nodiscard]] bool isChecked() const;

    };
}


#endif //ZERROLITESFML_CHECKBOXSTYLE_H
