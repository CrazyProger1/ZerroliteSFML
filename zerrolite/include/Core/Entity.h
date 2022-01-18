//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_ENTITY_H
#define ZERROLITESFML_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    class Entity {
    private:
        sf::RenderWindow *m_pParentWindow = nullptr;

        fVector m_position;
    public:
        virtual void initialize();

        virtual void draw(sf::RenderTarget &rt);

        virtual void updateState();

        virtual void handleSFMLEvent(sf::Event &event);

        virtual void move(const fVector & offset);

        virtual void setPosition(const fVector & position);

        void setParentWindow(sf::RenderWindow *window);

        sf::RenderWindow *getParentWindow();

        fVector &getPosition();


    };
}


#endif //ZERROLITESFML_ENTITY_H
