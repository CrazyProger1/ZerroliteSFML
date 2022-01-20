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
    TStr sBuffer = readFile(configFilepath);
    nlohmann::json jsonBuffer = nlohmann::json::parse(sBuffer);

    WindowConfig windowConfig;

    windowConfig.fullscreen = jsonBuffer["fullscreen"];
    windowConfig.title = jsonBuffer["title"];
    windowConfig.height = jsonBuffer["height"];
    windowConfig.width = jsonBuffer["width"];

    return windowConfig;
}

zl::TStr zl::ConfigManager::readFile(const zl::TStr &filepath) {
    TStr sOut, sBuffer;
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Unable to open file <" << filepath << std::endl << ">";
        throw std::exception();
    }

    while (std::getline(file, sBuffer)) {
        sOut += sBuffer;
    }
    file.close();

    return sOut;
}
