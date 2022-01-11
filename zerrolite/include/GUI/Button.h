//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_BUTTON_H
#define ZERROLITESFML_BUTTON_H

#include "../Core/Entity.h"
#include "./Text.h"
#include <string>
#include <utility>
#include <iostream>

namespace zl {
    class Button : public Entity {
    private:
        bool m_isDeactivated = false;

        fVector m_size;
        fVector m_textOffset;

        int m_borderWidth = 0;
        int m_cornerRadius = 0;

        sf::RectangleShape m_mainRect;
        sf::RectangleShape m_sideRect;
        sf::CircleShape m_cornerCircle;

        sf::RectangleShape m_borderRect;
        sf::RectangleShape m_sideBorderRect;
        sf::CircleShape m_cornerBorderCircle;


        RGBAColor m_color = {50, 200, 0};
        RGBAColor m_hoverColor = {255, 0, 0};
        RGBAColor m_borderColor = {0, 0, 150};
        RGBAColor m_deactivatedColor = {100, 100, 100};

        bool m_isClicked = false;
        bool m_isHovered = false;

        bool m_centerText = false;
        bool m_isTextSet = false;

        Text m_text;
        RGBAColor m_textColor;
        RGBAColor m_textHoverColor;

        void init();

        void centralizeText();

        void checkClick(sf::Event &event);

        void checkHover();

        void drawBorder(sf::RenderTarget &rt);

    public:
        Button();

        explicit Button(const fVector &size,
                        const RGBAColor &color = {250, 0, 100},
                        const RGBAColor &hoverColor = {0, 250, 0},
                        Text *text = nullptr,
                        const fVector &textOffset = {0, 0},
                        int borderWidth = 0,
                        const RGBAColor &borderColor = {100, 100, 100},
                        bool centerText = false,
                        int cornerRadius = 0
        );

        void initialize() override;


        void setSize(const fVector &size);

        void setTextOffset(const fVector &offset);

        void setBorderWidth(int width);

        void setColor(const RGBAColor &color);

        void setDeactivatedColor(const RGBAColor &color);

        void setHoverColor(const RGBAColor &color);

        void setBorderColor(const RGBAColor &color);

        void setCornerRadius(int radius);

        void setCenteringText(bool center = true);

        void setText(Text &text);


        void draw(sf::RenderTarget &rt) override;


        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;

        bool isClicked();

//
        bool isHovered();

        void activate();

        void deactivate();


    };
}


#endif //ZERROLITESFML_BUTTON_H
