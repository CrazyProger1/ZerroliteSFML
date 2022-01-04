//
// Created by crazy on 27.12.2021.
//

#ifndef ZERROLITESFML_SCENE_H
#define ZERROLITESFML_SCENE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "./Entity.h"


namespace zl {
    class Scene {
    private:
        std::vector<Entity *> m_entitiesContainer;
    public:

        virtual void draw(sf::RenderWindow &renderWindow);

        virtual void handleSFMLEvent(sf::Event &event);

        virtual void entitiesInitialization();

        virtual void updateState();

        void attach(Entity &entity);
    };
}


#endif //ZERROLITESFML_SCENE_H
