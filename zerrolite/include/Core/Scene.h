//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_SCENE_H
#define ZERROLITESFML_SCENE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "./Entity.h"
#include "../Containers/Container.h"
#include "./GlobalDataStorage.h"

namespace zl {
    class Scene {
        /////////////////////////////
        /// Heritable class, which is responsible for drawing and updating entities.
        /////////////////////////////

    private:
        sf::RenderWindow *m_pParentWindow = nullptr;

        TStr m_sNewScene;

        std::vector<Entity *> m_entitiesContainer;

        sf::Vector2u m_resolution;

    public:
        void attach(Entity *entity);
        /////////////////////////////
        /// This method attaches entities to screen and updates it.
        /////////////////////////////

        void attach(Container *container);
        /////////////////////////////
        /// This method attaches entities from container to screen and updates it.
        /////////////////////////////


        void draw(sf::RenderTarget &rt);
        /////////////////////////////
        /// This method draws all entities. Also it fill and display window.
        /////////////////////////////

        void initializeScene();

        void updateState();
        /////////////////////////////
        /// This method updates all entities.
        /////////////////////////////

        void handleSFMLEvent(sf::Event &event);


        void setParentWindow(sf::RenderWindow *window);

        void setNewScene(const TStr &sceneName);


        sf::RenderWindow *getParentWindow();

        TStr &getNewScene();

        sf::Vector2u &getWindowResolution();


        static GlobalDataStorage *getGlobalStorage();

        /////////////////////////////
        /// This virtual methods are called by game core on certain events.
        virtual void onInitializeScene();

        virtual void onLoadResources();

        virtual void onDraw(sf::RenderTarget &rt);

        virtual void onUpdateState();

        virtual void onDestroy();

        virtual void onSFMLEvent(sf::Event &event);
        /////////////////////////////
    };
}


#endif //ZERROLITESFML_SCENE_H
