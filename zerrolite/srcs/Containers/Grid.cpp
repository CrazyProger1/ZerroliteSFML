//
// Created by crazy on 12.01.2022.
//


#include "../../include/Containers/Grid.h"

std::vector<zl::Entity *> &zl::Grid::getEntities() {
    return m_entitiesContainer;
}

void zl::Grid::addEntity(zl::Entity *entity) {
    m_entitiesContainer.emplace_back(entity);
}
