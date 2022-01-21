//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_ENTITY_H
#define ZERROLITESFML_ENTITY_H

#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    class Entity {
        /////////////////////////////
        /// Every object on screen except background and walls is a entity.
        /////////////////////////////
    private:
        sf::RenderWindow *m_pParentWindow = nullptr;

        sf::Vector2f m_position;

        TStr m_sType = "entity";

    public:
        Entity();

        explicit Entity(const sf::Vector2f &position);


        void setParentWindow(sf::RenderWindow *window);

        void setType(const TStr &type);

        virtual void setPosition(const sf::Vector2f &position);

        virtual void setPosition(float x, float y);


        sf::RenderWindow *getParentWindow();

        virtual sf::Vector2f &getPosition();

        TStr &getType();


        virtual void onAttach();
        /////////////////////////////
        /// This method is called by scene when entity is attached.
        /////////////////////////////

        virtual void initialize();
        /////////////////////////////
        /// This method is called after some setter has been applied. It is called for recounting internal variables.
        /////////////////////////////

        virtual void draw(sf::RenderTarget &rt);

        virtual void updateState();

        virtual void handleSFMLEvent(sf::Event &event);

        /////////////////////////////
        /// This methods apply to move entity.
        virtual void move(const sf::Vector2f &offset);

        virtual void move(float offsetX, float offsetY);
        /////////////////////////////


    };
}


#endif //ZERROLITESFML_ENTITY_H
