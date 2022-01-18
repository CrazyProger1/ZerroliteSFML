//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_GAMECORE_H
#define ZERROLITESFML_GAMECORE_H

#include <SFML/Graphics.hpp>
#include <map>
#include "./Scene.h"

namespace zl {
    typedef std::map<str, Scene *> Scenes;

    class GameCore {

    private:
        Scene *m_pActiveScene = nullptr;
        sf::RenderWindow *m_pMainWindow = nullptr;
        sf::Vector2u m_resolution;

        Scenes m_scenes;

        void tick();

        void handleSFMLEvents();

    public:
        GameCore();

        explicit GameCore(sf::RenderWindow *mainWindow);

        void run();

        void setActiveScene(const str &name);

        void setMainWindow(sf::RenderWindow *window);

        void addScene(const str &name, Scene *scene);

        void terminate();
    };

}

#endif //ZERROLITESFML_GAMECORE_H
