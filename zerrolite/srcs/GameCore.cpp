//
// Created by crazy on 27.12.2021.
//

#include "../include/GameCore.h"

namespace zl {

    GameCore::GameCore() = default;

    GameCore::GameCore(sf::RenderWindow *mainWindow) {
        m_pMainWindow = mainWindow;
    }

    void GameCore::setMainWindow(sf::RenderWindow *mainWindow) {
        m_pMainWindow = mainWindow;
    }


}
