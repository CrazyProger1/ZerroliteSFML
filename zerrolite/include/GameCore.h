//
// Created by crazy on 27.12.2021.
//

#ifndef ZERROLITESFML_GAMECORE_H
#define ZERROLITESFML_GAMECORE_H

#include <SFML/Graphics.hpp>
#include "./Scene.h"


namespace zl {
    class GameCore {
    private:
        sf::RenderWindow *m_pMainWindow{};
        bool m_stop = false;
        Scene *m_pActiveScene{};

    public:
        GameCore();

        explicit GameCore(sf::RenderWindow *mainWindow);

        void setMainWindow(sf::RenderWindow *mainWindow);

        void setActiveScene(Scene *scene);

        void run();


    };

}


#endif //ZERROLITESFML_GAMECORE_H
