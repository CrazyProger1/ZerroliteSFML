//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_PLAYER_H
#define ZERROLITESFML_PLAYER_H

#include "./Actor.h"

namespace zl {
    class Player : public Actor {
        /////////////////////////////
        /// Just a wrapper for actor.
        /////////////////////////////

    private:

    public:
        void initialize() override;


        void onSFMLEvent(sf::Event &event) override;

        void onUpdateState() override;

        void onLoadResources() override;

        void onInitializeActor() override;

        void onDraw(sf::RenderTarget &rt) override;


    };
}


#endif //ZERROLITESFML_PLAYER_H
