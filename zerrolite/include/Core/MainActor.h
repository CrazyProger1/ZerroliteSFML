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

    public:
        void initialize() override;


        void onSFMLEvent(sf::Event &event) override;

        void onUpdateState() override;

        void onLoadResources() override;

        void onInitializeActor() override;

        void onDraw(sf::RenderTarget &rt) override;


    };
}


#endif //ZERROLITESFML_MAINACTOR_H
