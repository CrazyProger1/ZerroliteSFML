//
// Created by crazy on 04.01.2022.
//

#ifndef ZERROLITESFML_ENTITY_H
#define ZERROLITESFML_ENTITY_H

#include <SFML/Graphics.hpp>
#include "types.h"

namespace zl {

    class Entity {
    private:
        fCoords m_position;
    public:
        Entity();

        explicit Entity(fCoords &position);

        virtual void draw(sf::RenderTarget &renderTarget);

        void setPosition(fCoords coords);

        void move(fCoords &offset);

        fCoords &getPosition();
    };

}


#endif //ZERROLITESFML_ENTITY_H
