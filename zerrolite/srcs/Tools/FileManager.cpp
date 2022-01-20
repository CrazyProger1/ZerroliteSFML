//
// Created by crazy on 20.01.2022.
//

#include "../../include/Tools/FileManager.h"

zl::TStr zl::FileManager::readFile(const zl::TStr &filepath) {
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

nlohmann::json zl::FileManager::loadJson(const zl::TStr &filepath) {
    TStr sBuffer = readFile(filepath);
    nlohmann::json jsonBuffer = nlohmann::json::parse(sBuffer);
    return jsonBuffer;
}
