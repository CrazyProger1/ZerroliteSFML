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
        bool m_isDeactivated = false;

        fVector m_size;
        fVector m_textOffset;

        int m_borderWidth = 0;
        int m_cornerRadius = 0;

        RGBAColor m_color = {50, 200, 0};
        RGBAColor m_hoverColor = {255, 0, 0};
        RGBAColor m_borderColor = {0, 0, 150};
        RGBAColor m_deactivatedColor = {100, 100, 100};

        bool m_centerText = false;
    public:

        explicit ButtonStyle(const fVector &size,
                             const RGBAColor &color = {250, 0, 100},
                             const RGBAColor &hoverColor = {0, 250, 0},
                             const fVector &textOffset = {0, 0},
                             int borderWidth = 0,
                             const RGBAColor &borderColor = {100, 100, 100},
                             bool centerText = false,
                             int cornerRadius = 0,
                             bool isDeactivated = false,
                             const RGBAColor &deactivatedColor = {100, 100, 100});

        bool isDeactivated();

        fVector getSize();

        fVector getTextOffset();

        int getBorderWidth();

        int getCornerRadius();

        RGBAColor &getColor();

        RGBAColor &getHoverColor();

        RGBAColor &getBorderColor();

        RGBAColor &getDeactivatedColor();

        bool centerText();


    };
}


#endif //ZERROLITESFML_BUTTONSTYLE_H
