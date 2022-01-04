//
// Created by crazy on 04.01.2022.
//

#ifndef ZERROLITESFML_ENTITY_H
#define ZERROLITESFML_ENTITY_H

#include <SFML/Graphics.hpp>

namespace zl {
    class Entity {
    public:
        virtual void draw(sf::RenderTarget &renderTarget);
    };

}


#endif //ZERROLITESFML_ENTITY_H
