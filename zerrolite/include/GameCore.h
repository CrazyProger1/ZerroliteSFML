//
// Created by crazy on 27.12.2021.
//

#ifndef ZERROLITESFML_GAMECORE_H
#define ZERROLITESFML_GAMECORE_H

#include <SFML/Graphics.hpp>

namespace zl {
    class GameCore {
    private:
        sf::RenderWindow *m_pMainWindow{};

    public:
        GameCore();

        explicit GameCore(sf::RenderWindow *mainWindow);

        void setMainWindow(sf::RenderWindow *mainWindow);
    };

}


#endif //ZERROLITESFML_GAMECORE_H
