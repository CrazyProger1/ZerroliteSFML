//
// Created by crazy on 27.12.2021.
//

#ifndef ZERROLITESFML_SCENE_H
#define ZERROLITESFML_SCENE_H

#include <SFML/Graphics.hpp>
#include "./Entity.h"

namespace zl {
    class Scene {
    private:

    public:

        virtual void draw(sf::RenderTarget &renderTarget);

        virtual void handleSFMLEvent(sf::Event &event);

        virtual void entitiesInitialization();

        virtual void updateState();

//        void attach();
    };
}


#endif //ZERROLITESFML_SCENE_H
