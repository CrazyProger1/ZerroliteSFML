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

        static GlobalDataStorage *p_instance;

        GlobalDataStorage() {}

        GlobalDataStorage(const GlobalDataStorage &);

        GlobalDataStorage &operator=(GlobalDataStorage &);

    public:
        static GlobalDataStorage *getInstance() {
            if (!p_instance)
                p_instance = new GlobalDataStorage();
            return p_instance;
        }

        void setValue(const TStr &name, const TStr &value);

        void setValue(const TStr &name, int value);


        TStr &getStringValue(const TStr &name);

        int getIntValue(const TStr &name);

    };
}


#endif //ZERROLITESFML_GLOBALDATASTORAGE_H
