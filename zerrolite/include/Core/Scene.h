//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_SCENE_H
#define ZERROLITESFML_SCENE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "./Entity.h"


namespace zl {
    class Scene {
    private:
        sf::RenderWindow *m_pParentWindow = nullptr;
        str m_pNewScene;

        std::vector<Entity *> m_entitiesContainer;
    public:
        virtual void onInitializeScene();

        virtual void onLoadResources();

        virtual void onDraw(sf::RenderTarget &rt);

        virtual void onUpdateState();

        virtual void onDestroy();

        virtual void onSFMLEvent(sf::Event &event);

        void attach(Entity *entity);

        void draw(sf::RenderTarget &rt);

        void initializeScene();

        void updateState();

        void handleSFMLEvent(sf::Event &event);

        void setParentWindow(sf::RenderWindow *window);

        void setNewScene(const str &sceneName);

        str &getNewScene();
    };
}


#endif //ZERROLITESFML_SCENE_H
