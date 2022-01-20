//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_LANGUAGEMANAGER_H
#define ZERROLITESFML_LANGUAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../types.h"
#include "./FileManager.h"

namespace zl {


    class LanguageManager {
    private:
        nlohmann::json m_loadedChapter;
    public:
        LanguageManager();

        LanguageManager(const TStr &packFilepath, const TStr &chapter);

        void loadChapter(const TStr &packFilepath, const TStr &chapter);

        TStr getTranslatedString(const TStr &name);

    };
}


#endif //ZERROLITESFML_LANGUAGEMANAGER_H
