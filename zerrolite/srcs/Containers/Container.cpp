//
// Created by crazy on 17.01.2022.
//

#include "../../include/Containers/Container.h"

void zl::Container::move(zl::fVector offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
    initialize();
}

void zl::Container::setPosition(zl::fVector position) {
    m_position = position;
    initialize();
}

zl::fVector &zl::Container::getPosition() {
    return m_position;
}

void zl::Container::initialize() {

}





