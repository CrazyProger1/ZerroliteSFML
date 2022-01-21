//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_GLOBALDATASTORAGE_H
#define ZERROLITESFML_GLOBALDATASTORAGE_H

#include <iostream>
#include <map>
#include "../types.h"

//GlobalDataStorage *globalDataStorage = GlobalDataStorage::getInstance();

namespace zl {
    class GlobalDataStorage {
    private:

        std::map<TStr, TStr> m_stringVars;

        std::map<TStr, int> m_intVars;

        sf::Clock m_globalClock;

        static GlobalDataStorage *m_pInstance;

        GlobalDataStorage() {}

        GlobalDataStorage(const GlobalDataStorage &);

        GlobalDataStorage &operator=(GlobalDataStorage &);

    public:
        static GlobalDataStorage *getInstance() {
            if (!m_pInstance)
                m_pInstance = new GlobalDataStorage();

            return m_pInstance;
        }

        void setValue(const TStr &name, const TStr &value);

        void setValue(const TStr &name, int value);


        TStr &getStringValue(const TStr &name);

        int getIntValue(const TStr &name);


        sf::Clock &getGlobalClock();

    };
}


#endif //ZERROLITESFML_GLOBALDATASTORAGE_H
