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
#include "../Styles/ButtonStyle.h"
#include "./Image.h"

namespace zl {
    class Button : public Entity {
    private:
        bool m_bIsDeactivated = false;

        sf::Vector2f m_size;
        sf::Vector2f m_textOffset;
        sf::Vector2f m_imageOffset;

        int m_iBorderWidth = 0;
        int m_iCornerRadius = 0;

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

        bool m_bIsClicked = false;
        bool m_bIsHovered = false;

        bool m_bCenterText = false;
        bool m_bIsTextSet = false;

        bool m_bCenterImage = false;
        bool m_bIsImageSet = false;

        Text *m_pText;
        RGBAColor m_textColor;
        RGBAColor m_textHoverColor;

        Image *m_pImage;

        bool m_bJustHovered = false; // for optimization

        void centralizeText();

        void centralizeImage();

        void checkClick(sf::Event &event);
        /////////////////////////////
        /// This method check if button was clicked.
        /////////////////////////////

        void checkHover();
        /////////////////////////////
        /// This method check if cursor is hovered above button.
        /////////////////////////////

        void drawBorder(sf::RenderTarget &rt);

    public:
        Button();

        explicit Button(const sf::Vector2f &size,
                        const RGBAColor &color = {250, 0, 100},
                        const RGBAColor &hoverColor = {0, 250, 0},
                        Text *text = nullptr,
                        Image *image = nullptr,
                        const sf::Vector2f &textOffset = {0, 0},
                        const sf::Vector2f &imageOffset = {0, 0},
                        int borderWidth = 0,
                        const RGBAColor &borderColor = {100, 100, 100},
                        bool centerText = false,
                        bool centerImage = false,
                        int cornerRadius = 0
        );

        void initialize() override;


        void setSize(const sf::Vector2f &size);

        void setSize(float w, float h);

        void setTextOffset(const sf::Vector2f &offset);

        void setImageOffset(const sf::Vector2f &offset);

        void setBorderWidth(int width);

        void setColor(const RGBAColor &color);

        void setDeactivatedColor(const RGBAColor &color);

        void setHoverColor(const RGBAColor &color);

        void setBorderColor(const RGBAColor &color);

        void setCornerRadius(int radius);

        void setCenteringText(bool center = true);

        void setCenteringImage(bool center = true);

        void setText(Text &text);

        void setImage(Image &image);

        void setStyle(ButtonStyle &buttonStyle);


        bool isClicked();

        bool isHovered() const;


        void activate();

        void deactivate();


        void draw(sf::RenderTarget &rt) override;

        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;


    };
}


#endif //ZERROLITESFML_BUTTON_H
