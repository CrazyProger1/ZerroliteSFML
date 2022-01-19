//
// Created by crazy on 17.01.2022.
//

#ifndef ZERROLITESFML_CONTAINER_H
#define ZERROLITESFML_CONTAINER_H

#include <SFML/Graphics.hpp>
#include "../types.h"
#include "../Core/Entity.h"

namespace zl {
    class Container {
        /////////////////////////////
        /// Containers is used for alignment of entities.
        /////////////////////////////

    private:

        sf::Vector2f m_position;


    public:
        virtual void initialize();


        void setPosition(const sf::Vector2f &position);

        void setPosition(float x, float y);


        sf::Vector2f &getPosition();

        virtual std::vector<Entity *> &getEntities() = 0;


        void move(const sf::Vector2f &offset);

        void move(float offsetX, float offsetY);


    };
}


#endif //ZERROLITESFML_CONTAINER_H
