//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_TEXT_H
#define ZERROLITESFML_TEXT_H


#include "../Core/Entity.h"
#include <string>
#include <utility>
#include <iostream>
#include "../Styles/TextStyle.h"

namespace zl {
    class Text : public Entity {
    private:
        str m_textString;
        str m_fontFilepath = "../resources/fonts/arial.ttf";
        unsigned int m_textSFMLStyle = 0;
        int m_fontSize = 20;
        int m_underlineOffset = 5;
        int m_underlineWidth = 0;


        sf::Font m_font;
        sf::Text m_text;


        RGBAColor m_textColor = {30, 0, 200};
        RGBAColor m_underlineColor = {200, 100, 0};
        RGBAColor m_textHoverColor = {0, 0, 250};
        RGBAColor m_underlineHoverColor = {100, 200, 0};

        sf::RectangleShape m_underlineRect;

        bool m_isClicked = false;
        bool m_isHovered = false;

        bool m_justHovered = false; // for optimization

        void init();

        void checkClick(sf::Event &event);

        void checkHover();


    public:
        Text();

        explicit Text(const str &text,
                      const str &fontFilepath = "../resources/fonts/arial.ttf",
                      int fontSize = 20,
                      unsigned int textSFMLStyle = 0,
                      int underlineOffset = 0,
                      int underlineWidth = 0,
                      const RGBAColor &textColor = {100, 100, 100},
                      const RGBAColor &underlineColor = {20, 100, 200},
                      const RGBAColor &textHoverColor = {200, 200, 200},
                      const RGBAColor &underlineHoverColor = {100, 100, 250});

        void initialize() override;

        void setText(const str &text);

        void setFont(const str &filepath);

        void setFontSize(int size);

        void setUnderlineOffset(int offset);

        void setUnderlineWidth(int width);

        void setTextColor(const RGBAColor &color);

        void setUnderlineColor(const RGBAColor &color);

        void setTextHoverColor(const RGBAColor &color);

        void setUnderlineHoverColor(const RGBAColor &color);

        void setTextSFMLStyle(unsigned int style);

        void setStyle(TextStyle &style);

        void draw(sf::RenderTarget &renderTarget) override;

        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;

        bool isHovered();

        bool isClicked();

        str &getText();

        fVector getSize();

        fVector getFullSize();

        RGBAColor &getTextHoverColor();

        RGBAColor &getTextColor();


    };
}

#endif //ZERROLITESFML_TEXT_H
