//
// Created by crazy on 20.01.2022.
//

#include "../../include/Tools/ConfigManager.h"


zl::WindowConfig::WindowConfig() = default;

zl::WindowConfig::WindowConfig(int width, int height, const zl::TStr &title, bool fullscreen) {
    this->width = width;
    this->height = height;
    this->title = title;
    this->fullscreen = fullscreen;
}

zl::WindowConfig::WindowConfig(const sf::Vector2i &size, const zl::TStr &title, bool fullscreen) {
    this->width = size.x;
    this->height = size.y;
    this->title = title;
    this->fullscreen = fullscreen;
}


zl::WindowConfig zl::ConfigManager::loadWindowConfig(const zl::TStr &configFilepath) {
    nlohmann::json jsonBuffer = FileManager::loadJson(configFilepath);

    WindowConfig windowConfig;

    windowConfig.fullscreen = jsonBuffer["fullscreen"];
    windowConfig.title = jsonBuffer["title"];
    windowConfig.height = jsonBuffer["height"];
    windowConfig.width = jsonBuffer["width"];

    return windowConfig;
}


