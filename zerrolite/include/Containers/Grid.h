//
// Created by crazy on 12.01.2022.
//

#ifndef ZERROLITESFML_GRID_H
#define ZERROLITESFML_GRID_H

#include "./Container.h"
#include <iostream>

namespace zl {
    class Grid : public Container {
        /////////////////////////////
        /// Grid is a very comfortable container which apply...
        /////////////////////////////

    private:
        std::vector<Entity *> m_entitiesContainer;

    public:
        Grid() = default;


        void addEntity(Entity *entity);


        std::vector<Entity *> &getEntities() override;
    };
}


#endif //ZERROLITESFML_GRID_H
