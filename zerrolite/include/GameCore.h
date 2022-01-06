//
// Created by crazy on 27.12.2021.
//

#ifndef ZERROLITESFML_GAMECORE_H
#define ZERROLITESFML_GAMECORE_H

#include <SFML/Graphics.hpp>
#include "./Scene.h"
#include <iostream>

namespace zl {
    class GameCore {
    private:
        sf::RenderWindow *m_pMainWindow{};
        Scene *m_pActiveScene{};


        void handleSFMLEvents();

        void tick();

    public:
        GameCore();

        explicit GameCore(sf::RenderWindow *mainWindow);

        void setMainWindow(sf::RenderWindow *mainWindow);

        void setActiveScene(Scene *scene);

        void run();

        void terminate();


    };

}


#endif //ZERROLITESFML_GAMECORE_H
