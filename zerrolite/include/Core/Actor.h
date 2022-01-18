//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_ACTOR_H
#define ZERROLITESFML_ACTOR_H

#include "./Entity.h"
#include <iostream>
#include <cmath>

namespace zl {
    class Actor : public Entity {
    private:
        fVector m_position;

        float m_angle = 0;

        sf::Sprite *m_sprite;


    public:
        void move(const fVector &offset) override;

        void draw(sf::RenderTarget &rt) override;

        void rotate(float angle);

        void setPosition(const fVector &position) override;

        void setSprite(sf::Sprite *sprite);

        void setRotation(float angle);

        void turnToMouseCursor();

        void initialize() override;
    };

}


#endif //ZERROLITESFML_ACTOR_H
