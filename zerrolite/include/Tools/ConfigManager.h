//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_CONFIGMANAGER_H
#define ZERROLITESFML_CONFIGMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "./nlohmann/json.hpp"
#include "./FileManager.h"
#include "../types.h"

namespace zl {
    struct WindowConfig {
        int width = 0;
        int height = 0;
        TStr title = "New Game";
        bool fullscreen = false;

        WindowConfig();

        WindowConfig(int width, int height, const TStr &title, bool fullscreen);

        WindowConfig(const sf::Vector2i &size, const TStr &title, bool fullscreen);
    };

    class ConfigManager {

    public:
        static WindowConfig loadWindowConfig(const TStr &configFilepath);
    };
}


#endif //ZERROLITESFML_CONFIGMANAGER_H
