//
// Created by crazy on 12.01.2022.
//

#ifndef ZERROLITESFML_TEXTSTYLE_H
#define ZERROLITESFML_TEXTSTYLE_H

#include <string>
#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    struct TextStyle {
        str m_fontFilepath = "../resources/fonts/arial.ttf";
        unsigned int m_textSFMLStyle = 0;
        int m_fontSize = 20;
        int m_underlineOffset = 5;
        int m_underlineWidth = 0;

        RGBAColor m_textColor = {30, 0, 200};
        RGBAColor m_underlineColor = {200, 100, 0};
        RGBAColor m_textHoverColor = {0, 0, 250};
        RGBAColor m_underlineHoverColor = {100, 200, 0};

        explicit TextStyle(
                const str &fontFilepath = "../resources/fonts/arial.ttf",
                int textSFMLStyle = 0,
                int fontSize = 20,
                int underlineOffset = 5,
                int underlineWidth = 0,
                const RGBAColor &textColor = {30, 0, 200},
                const RGBAColor &underlineColor = {200, 100, 0},
                const RGBAColor &textHoverColor = {0, 0, 250},
                const RGBAColor &underlineHoverColor = {100, 200, 0}


        );

        str getFontFilepath();

        unsigned int getTextSFMLStyle();

        int getFontSize();

        int getUnderlineOffset();

        int getUnderlineWidth();

        RGBAColor &getTextColor();

        RGBAColor &getTextHoverColor();

        RGBAColor &getUnderlineColor();

        RGBAColor &getUnderlineHoverColor();
    };
}


#endif //ZERROLITESFML_TEXTSTYLE_H
