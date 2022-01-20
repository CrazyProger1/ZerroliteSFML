//
// Created by crazy on 20.01.2022.
//

#include "../../include/Tools/LanguageManager.h"


zl::LanguageManager::LanguageManager() = default;

zl::LanguageManager::LanguageManager(const zl::TStr &packFilepath, const zl::TStr &chapter) {
    m_loadedChapter = FileManager::loadJson(packFilepath)[chapter];
}

void zl::LanguageManager::loadChapter(const zl::TStr &packFilepath, const zl::TStr &chapter) {
    m_loadedChapter = FileManager::loadJson(packFilepath)[chapter];
}

zl::TStr zl::LanguageManager::getTranslatedString(const zl::TStr &name) {
    TStr sBuffer = m_loadedChapter[name];
    return sBuffer;
}
