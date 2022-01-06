//
// Created by crazy on 05.01.2022.
//

#ifndef ZERROLITESFML_TEXT_H
#define ZERROLITESFML_TEXT_H

#include "../Entity.h"
#include <string>
#include <utility>
#include <iostream>

namespace zl {
    class Text : public Entity {
    private:
        str m_text;
        str m_font;
        int m_fontSize = 20;
        int m_underlineOffset = 5;
        int m_underlineWidth = 0;

        sf::Font m_sf_font;
        sf::Text m_sf_text;


        RGBAColor m_textColor = {30, 0, 200};
        RGBAColor m_underlineColor = {200, 100, 0};
        RGBAColor m_textHoverColor = {0, 0, 250};
        RGBAColor m_underlineHoverColor = {100, 200, 0};

        sf::RectangleShape m_underlineRect;

        bool m_isClicked = false;

        void init();

    public:

        void initialize();


        Text();

        Text(const str &text, const str &font, int fontSize, int underlineOffset, int underlineWidth,
             const RGBAColor &textColor,
             const RGBAColor &underlineColor, const RGBAColor &textHoverColor, const RGBAColor &underlineHoverColor);

        void setText(const str &text);

        str getText();

        void setFont(const str &font);

        void setFontSize(int size);

        void setUnderlineOffset(int offset);

        void setUnderlineWidth(int width);

        void setTextColor(const RGBAColor &color);

        void setUnderlineColor(const RGBAColor &color);

        void setTextHoverColor(const RGBAColor &color);

        void setUnderlineHoverColor(const RGBAColor &color);

        bool isHovered();

        void draw(sf::RenderTarget &renderTarget) override;

        void handleSFMLEvent(sf::Event &event) override;

        bool isClicked();

        fSize getTextSize();

        fSize getFullSize();
    };
}


#endif //ZERROLITESFML_TEXT_H
