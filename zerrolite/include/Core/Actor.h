//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_ACTOR_H
#define ZERROLITESFML_ACTOR_H

#include <iostream>
#include <cmath>
#include "./Animation.h"
#include "./Entity.h"

namespace zl {
    class Actor : public Entity {
        /////////////////////////////
        /// Actor is any player or NPC.
        /// In this type of entity initialize() does not use for more speed, every operation must be fully ended.
        /////////////////////////////

    private:
        sf::Vector2f m_position;
        sf::Vector2u m_size;

        float m_fltAngle = 0;
        float m_fltSpeed = 0;

        sf::Sprite *m_pSprite{};

        sf::CircleShape m_originCircle;

        sf::Clock *m_sceneClock{};


        TStr m_sActiveAppearance;

        TStr m_sActiveAnimation;


        std::map<TStr, sf::Texture> m_appearances;

        std::map<TStr, sf::Vector2f> m_originOffsets;

        std::map<TStr, Animation> m_animations;


        bool m_bOriginShowed = false;


        static sf::Vector2f calculateSpeed(float angle, float speed);
        /////////////////////////////
        /// This method calculate speed vector depending on angle.
        /////////////////////////////

    public:
        Actor();

        explicit Actor(const sf::Vector2f &position);

        void initialize() override;

        void setPosition(const sf::Vector2f &position) override;

        void setPosition(float x, float y) override;

        void setSprite(sf::Sprite *sprite);

        void setRotation(float angle);

        void setAppearance(const TStr &appearance);

        void setSpeed(float speed);

        void setSceneClock(sf::Clock *clock) override;


        void addAppearance(const TStr &name, sf::Texture &texture, const sf::Vector2f &originOffset = {0, 0});

        void addAnimation(const TStr &name, Animation &animation);


        sf::Vector2f &getPosition() override;

        sf::Clock &getSceneClock();


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


        void showOrigin();

        void hideOrigin();


        void showAnimation(const TStr &name);


        void turnToMouseCursor();
        /////////////////////////////
        /// This methods apply player or NPC to turn to cursor.
        /////////////////////////////

        void onAttach() override;


        /////////////////////////////
        /// MainActor or NPC moving methods
        virtual void moveForward(float speedFactor);

        virtual void moveBack(float speedFactor);

        virtual void moveRight(float speedFactor);

        virtual void moveLeft(float speedFactor);
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
