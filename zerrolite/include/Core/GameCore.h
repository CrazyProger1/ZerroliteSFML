//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_GAMECORE_H
#define ZERROLITESFML_GAMECORE_H

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <thread>
#include <functional>
#include "./Scene.h"


namespace zl {
    typedef std::map<TStr, Scene *> TScenes;

    class GameCore {
        /////////////////////////////
        /// Main heritable class, core of game. It controls mainloop and window.
        /////////////////////////////

    private:
        Scene *m_pActiveScene = nullptr;

        sf::RenderWindow *m_pMainWindow = nullptr;

        sf::Vector2u m_resolution;

        TScenes m_scenes;

        int m_iFps = 0;


        void tick();
        /////////////////////////////
        /// This method calls handleSFMLEvents(), scene updating method and scene drawing.
        /////////////////////////////

        void handleSFMLEvents();
        /////////////////////////////
        /// This method handles SFML events and calls scene handler.
        /////////////////////////////

    public:
        GameCore();

        explicit GameCore(sf::RenderWindow *mainWindow);


        void setActiveScene(const TStr &name);

        void setMainWindow(sf::RenderWindow *window);

        void addScene(const TStr &name, Scene *scene);


        Scene *getActiveScene();

        sf::RenderWindow *getMainWindow();

        [[nodiscard]] int getFps() const;

        sf::Vector2u &getWindowResolution();


        void run();
        /////////////////////////////
        /// This method contains mainloop and calls tick() every iteration.
        /////////////////////////////

        void terminate();
    };

}

#endif //ZERROLITESFML_GAMECORE_H
