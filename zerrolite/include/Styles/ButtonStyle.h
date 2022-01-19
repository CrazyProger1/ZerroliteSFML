//
// Created by crazy on 12.01.2022.
//

#ifndef ZERROLITESFML_BUTTONSTYLE_H
#define ZERROLITESFML_BUTTONSTYLE_H

#include <string>
#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    struct ButtonStyle {
    private:
        bool m_bIsDeactivated = false;

        sf::Vector2f m_size;
        sf::Vector2f m_textOffset;
        sf::Vector2f m_imageOffset;

        int m_iBorderWidth = 0;
        int m_iCornerRadius = 0;

        RGBAColor m_color = {50, 200, 0};
        RGBAColor m_hoverColor = {255, 0, 0};
        RGBAColor m_borderColor = {0, 0, 150};
        RGBAColor m_deactivatedColor = {100, 100, 100};

        bool m_bCenterText = false;
        bool m_bCenterImage = false;
    public:

        explicit ButtonStyle(
                const sf::Vector2f &size,
                const RGBAColor &color = {250, 0, 100},
                const RGBAColor &hoverColor = {0, 250, 0},
                const sf::Vector2f &textOffset = {0, 0},
                const sf::Vector2f &imageOffset = {0, 0},
                int borderWidth = 0,
                const RGBAColor &borderColor = {100, 100, 100},
                bool centerText = false,
                bool centerImage = false,
                int cornerRadius = 0,
                bool isDeactivated = false,
                const RGBAColor &deactivatedColor = {100, 100, 100}
        );


        sf::Vector2f &getSize();

        sf::Vector2f &getTextOffset();

        sf::Vector2f &getImageOffset();

        [[nodiscard]] int getBorderWidth() const;

        [[nodiscard]] int getCornerRadius() const;

        RGBAColor &getColor();

        RGBAColor &getHoverColor();

        RGBAColor &getBorderColor();

        RGBAColor &getDeactivatedColor();


        [[nodiscard]] bool isDeactivated() const;


        [[nodiscard]] bool centerText() const;

        [[nodiscard]] bool centerImage() const;


    };
}


#endif //ZERROLITESFML_BUTTONSTYLE_H
