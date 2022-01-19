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

        virtual void onInitializeActor();

        virtual void onLoadResources();

//
        virtual void onDraw(sf::RenderTarget &rt);

        virtual void onUpdateState();

        virtual void onDestroy();

        virtual void onSFMLEvent(sf::Event &event);

        void onAttach() override;

        void move(const fVector &offset) override;

        void draw(sf::RenderTarget &rt) override;

        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;

        void rotate(float angle);

        void setPosition(const fVector &position) override;

        void setSprite(sf::Sprite *sprite);

        void setRotation(float angle);

        void setAppearance(unsigned int appearanceId);

        void addAppearance(unsigned int appearanceId, sf::Texture &texture);

//        virtual void moveForward();
//
//        virtual void moveBack();
//
//        virtual void moveRight();
//
//        virtual void moveLeft();
//
//        void setSpeed();




        void turnToMouseCursor();

        void initialize() override;
    };

}


#endif //ZERROLITESFML_ACTOR_H
