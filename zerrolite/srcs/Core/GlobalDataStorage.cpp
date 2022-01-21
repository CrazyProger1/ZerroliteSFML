//
// Created by crazy on 20.01.2022.
//

#include "../../include/Core/GlobalDataStorage.h"

zl::GlobalDataStorage *zl::GlobalDataStorage::m_pInstance = nullptr;

void zl::GlobalDataStorage::setValue(const zl::TStr &name, const zl::TStr &value) {
    m_stringVars[name] = value;
}

void zl::GlobalDataStorage::setValue(const zl::TStr &name, int value) {
    m_intVars[name] = value;
}

zl::TStr &zl::GlobalDataStorage::getStringValue(const zl::TStr &name) {
    return m_stringVars[name];
}

int zl::GlobalDataStorage::getIntValue(const zl::TStr &name) {
    return m_intVars[name];
}

sf::Clock &zl::GlobalDataStorage::getGlobalClock() {
    return m_globalClock;
}



