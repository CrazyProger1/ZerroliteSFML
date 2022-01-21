//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_MAINACTOR_H
#define ZERROLITESFML_MAINACTOR_H

#include "./Actor.h"

namespace zl {
    class MainActor : public Actor {
        /////////////////////////////
        /// Just a wrapper for actor.
        /////////////////////////////

    private:
        std::vector<int> m_pressedKeys;

    public:
        void initialize() override;


        std::vector<int> &getPressedKeys();

        void handleSFMLEvent(sf::Event &event) override;


        void onSFMLEvent(sf::Event &event) override;

        void onUpdateState() override;

        void onLoadResources() override;

        void onInitializeActor() override;

        void onDraw(sf::RenderTarget &rt) override;


        /////////////////////////////
        void moveForward(float speedFactor = 1) override;

        void moveBack(float speedFactor = 0.5) override;

        void moveRight(float speedFactor = 0.4) override;

        void moveLeft(float speedFactor = 0.4) override;
        /////////////////////////////


    };
}


#endif //ZERROLITESFML_MAINACTOR_H
