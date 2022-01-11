//
// Created by crazy on 04.01.2022.
//

#ifndef ZERROLITESFML_BUTTON_H
#define ZERROLITESFML_BUTTON_H

#include "../Entity.h"
#include "./txt.h"

namespace zl {
    class Button : public Entity {
    private:
        bool m_isDeactivated = false;

        fSize m_size;
        fSize m_textOffset;

        int m_borderWidth = 0;
        int m_cornerRadius = 0;


        sf::RectangleShape m_mainRect;
        sf::RectangleShape m_borderRect;

        RGBAColor m_color = {50, 200, 0};
        RGBAColor m_hoverColor = {255, 0, 0};
        RGBAColor m_borderColor = {0, 0, 150};
        RGBAColor m_deactivatedColor = {100, 100, 100};

        bool m_isClicked = false;
        bool m_centerText = false;
        bool isTextSet = false;

        Text m_text;
        RGBAColor m_textColor;
        RGBAColor m_textHoverColor;

        void init();

        void centralizeText();

    public:
        Button();

        Button(const fSize &size,
               const RGBAColor &color,
               const RGBAColor &hoverColor,
               const Text &text,
               const fSize &textOffset,
               int borderWidth,
               const RGBAColor &borderColor,
               bool centerText
        );

        void draw(sf::RenderTarget &renderTarget) override;

        void handleSFMLEvent(sf::Event &event) override;

        void setSize(const fSize &size);

        void setTextOffset(const fSize &offset);

        void setBorderWidth(int width);

        void setColor(const RGBAColor &color);

        void setDeactivatedColor(const RGBAColor &color);

        void setHoverColor(const RGBAColor &color);

        void setBorderColor(const RGBAColor &color);

        void setCornerRadius(int radius);

        void setCenterText(bool center = true);

        void setText(Text &text);

        bool isClicked();

        bool isHovered();

        void activate();

        void deactivate();


    };

}


#endif //ZERROLITESFML_BUTTON_H
