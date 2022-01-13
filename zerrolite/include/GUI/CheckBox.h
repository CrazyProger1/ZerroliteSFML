//
// Created by crazy on 13.01.2022.
//

#ifndef ZERROLITESFML_CHECKBOX_H
#define ZERROLITESFML_CHECKBOX_H

#include "../Core/Entity.h"
#include <string>
#include <utility>
#include <iostream>

namespace zl {
    class CheckBox : public Entity {
    private:
        fVector m_size;

        RGBAColor m_color;
    };
}


#endif //ZERROLITESFML_CHECKBOX_H
