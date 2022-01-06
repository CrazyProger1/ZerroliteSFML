//
// Created by crazy on 04.01.2022.
//

#ifndef ZERROLITESFML_ENTITY_H
#define ZERROLITESFML_ENTITY_H

#include <SFML/Graphics.hpp>
#include "types.h"
#include <iostream>

namespace zl {

    class Entity {
    private:
        fCoords m_position;

        sf::RenderWindow *m_pParentWindow = nullptr;
    public:
        Entity();

        explicit Entity(fCoords &position);

        virtual void draw(sf::RenderTarget &renderTarget);

        virtual void handleSFMLEvent(sf::Event &event);

        void setPosition(fCoords coords);

        void setParentWindow(sf::RenderWindow &window);

        sf::RenderWindow *getParentWindow();

        void move(fCoords &offset);

        fCoords &getPosition();
    };

}


#endif //ZERROLITESFML_ENTITY_H
