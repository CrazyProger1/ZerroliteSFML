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
    private:
        fVector m_position;


    public:
        virtual void initialize();

        void move(fVector offset);

        void setPosition(fVector position);

        fVector &getPosition();

        virtual std::vector<Entity *> &getEntities() = 0;


    };
}


#endif //ZERROLITESFML_CONTAINER_H
