//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_ACTOR_H
#define ZERROLITESFML_ACTOR_H

#include "./Entity.h"

namespace zl {
    class Actor : public Entity {
    private:
        fVector m_position;
        fVector m_size;


    public:
        void move(const fVector &offset) override;

        void setPosition(const fVector &position) override;
    };

}


#endif //ZERROLITESFML_ACTOR_H
