//
// Created by crazy on 18.01.2022.
//

#include "../../include/Core/Actor.h"

void zl::Actor::move(const fVector &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
}

void zl::Actor::setPosition(const fVector &position) {
    m_position = position;
}
