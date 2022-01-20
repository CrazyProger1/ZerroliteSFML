//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_FILEMANAGER_H
#define ZERROLITESFML_FILEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "./nlohmann/json.hpp"
#include "../types.h"

namespace zl {
    class FileManager {


    public:
        static TStr readFile(const zl::TStr &filepath);

        static nlohmann::json loadJson(const zl::TStr &filepath);
    };
}


#endif //ZERROLITESFML_FILEMANAGER_H
