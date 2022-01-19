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
        /////////////////////////////
        /// Actor is any player or NPC.
        /// In this type of entity initialize() does not use for more speed, every operation must be fully ended.
        /////////////////////////////

    private:
        sf::Vector2f m_position;
        sf::Vector2u m_size;
        sf::Vector2f m_speedVector;

        float m_fltAngle = 0;
        float m_fltSpeed = 0;

        sf::Sprite *m_pSprite{};

        int m_iActiveAppearanceId = 0;

        std::map<int, sf::Texture> m_appearances;


        void calculateSpeed();
        /////////////////////////////
        /// This method calculate speed vector depending on angle.
        /////////////////////////////

    public:
        Actor();

        explicit Actor(const sf::Vector2f &position);


        void setPosition(const sf::Vector2f &position) override;

        void setPosition(float x, float y) override;

        void setSprite(sf::Sprite *sprite);

        void setRotation(float angle);

        void setAppearance(unsigned int appearanceId);

        void setSpeed(float speed);


        void addAppearance(unsigned int appearanceId, sf::Texture &texture);


        void draw(sf::RenderTarget &rt) override;

        void handleSFMLEvent(sf::Event &event) override;

        void updateState() override;

        void rotate(float angle);
        /////////////////////////////
        /// This method apply turn player around center.
        /////////////////////////////


        /////////////////////////////
        /// This methods apply to move of player or NPC.
        void move(const sf::Vector2f &offset) override;

        void move(float offsetX, float offsetY) override;
        /////////////////////////////


        void turnToMouseCursor();
        /////////////////////////////
        /// This methods apply player or NPC to turn to cursor.
        /////////////////////////////

        void onAttach() override;


        /////////////////////////////
        /// Player or NPC moving methods
        virtual void moveForward();

        virtual void moveBack();

        virtual void moveRight();

        virtual void moveLeft();
        /////////////////////////////


        /////////////////////////////
        virtual void onInitializeActor();

        virtual void onLoadResources();

        virtual void onDraw(sf::RenderTarget &rt);

        virtual void onUpdateState();

        virtual void onSFMLEvent(sf::Event &event);
        /////////////////////////////


    };

}


#endif //ZERROLITESFML_ACTOR_H
