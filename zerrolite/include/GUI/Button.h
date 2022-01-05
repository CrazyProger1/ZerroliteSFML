//
// Created by crazy on 04.01.2022.
//

#ifndef ZERROLITESFML_BUTTON_H
#define ZERROLITESFML_BUTTON_H

#include "../Entity.h"

namespace zl {
    class Button : public Entity {
    private:
        bool m_isDeactivated = false;

        fSize m_size;
        int borderWidth = 0;

        sf::RectangleShape mainRect;
        sf::RectangleShape borderRect;

        RGBAColor color;
        RGBAColor borderColor;



    public:
        Button();

//        Button(fSize size);

        void draw(sf::RenderTarget &renderTarget) override;

        void activate();

        void deactivate();
    };

}


#endif //ZERROLITESFML_BUTTON_H
