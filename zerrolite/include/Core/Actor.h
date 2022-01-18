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
        uVector m_size;

        float m_angle = 0;


        sf::Sprite *m_pSprite{};

        int m_activeAppearanceId = 0;

        std::map<int, sf::Texture> m_appearances;


    public:
        Actor() = default;

        void move(const fVector &offset) override;

        void draw(sf::RenderTarget &rt) override;

        void rotate(float angle);

        void setPosition(const fVector &position) override;

        void setSprite(sf::Sprite *sprite);

        void setRotation(float angle);

        void setAppearance(unsigned int appearanceId);

        void addAppearance(unsigned int appearanceId, sf::Texture &texture);

        void turnToMouseCursor();

        void initialize() override;
    };

}


#endif //ZERROLITESFML_ACTOR_H
