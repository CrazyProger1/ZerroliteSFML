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
        Scene *m_pActiveScene;

    public:

        virtual void draw(sf::RenderWindow &renderWindow);

        virtual void handleSFMLEvent(sf::Event &event);

        virtual void initializeEntities();

        virtual void updateState();

        void attach(Entity &entity);

        void setSelfReference(Scene *scene);

        void setActiveScene(Scene *scene);

    };
}


#endif //ZERROLITESFML_SCENE_H
