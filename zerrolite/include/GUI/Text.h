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
        /////////////////////////////
        /// Very customizable text with big number of opportunities.
        /////////////////////////////
    private:
        TStr m_sText;
        TStr m_sFontFilepath = "../resources/fonts/arial.ttf";
        unsigned int m_uTextSFMLStyle = 0;
        int m_iFontSize = 20;
        int m_iUnderlineOffset = 5;
        int m_iUnderlineWidth = 0;


        sf::Font m_font;
        sf::Text m_text;


        RGBAColor m_textColor = {30, 0, 200};
        RGBAColor m_underlineColor = {200, 100, 0};
        RGBAColor m_textHoverColor = {0, 0, 250};
        RGBAColor m_underlineHoverColor = {100, 200, 0};

        sf::RectangleShape m_underlineRect;

        bool m_bIsClicked = false;
        bool m_bIsHovered = false;

        bool m_bJustHovered = false; // for optimization


        void checkClick(sf::Event &event);
        /////////////////////////////
        /// This method check if text was clicked.
        /////////////////////////////


        void checkHover();
        /////////////////////////////
        /// This method check if cursor is hovered above text.
        /////////////////////////////

    public:
        Text();

        explicit Text(
                const TStr &text,
                const TStr &fontFilepath = "../resources/fonts/arial.ttf",
                int fontSize = 20,
                unsigned int textSFMLStyle = 0,
                int underlineOffset = 0,
                int underlineWidth = 0,
                const RGBAColor &textColor = {100, 100, 100},
                const RGBAColor &underlineColor = {20, 100, 200},
                const RGBAColor &textHoverColor = {200, 200, 200},
                const RGBAColor &underlineHoverColor = {100, 100, 250}
        );

        void initialize() override;


        void setText(const TStr &text);

        void setFont(const TStr &filepath);

        void setFontSize(int size);

        void setUnderlineOffset(int offset);

        void setUnderlineWidth(int width);

        void setTextColor(const RGBAColor &color);

        void setUnderlineColor(const RGBAColor &color);

        void setTextHoverColor(const RGBAColor &color);

        void setUnderlineHoverColor(const RGBAColor &color);

        void setTextSFMLStyle(unsigned int style);

        void setStyle(TextStyle &style);


        TStr &getText();

        sf::Vector2f getSize();

        sf::Vector2f getFullSize();

        RGBAColor &getTextHoverColor();

        RGBAColor &getTextColor();


        bool isHovered();

        bool isClicked();


        void draw(sf::RenderTarget &renderTarget) override;

        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;
    };
}

#endif //ZERROLITESFML_TEXT_H
