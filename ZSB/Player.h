//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_PLAYER_H
#define ZERROLITESFML_PLAYER_H

#include <experimental/filesystem>
#include "../zerrolite/zerrolite.h"

class Player : public zl::MainActor {
private:
    sf::Sprite m_sprite;


    zl::TStr m_sSelectedWeapon = "rifle";
    zl::TStr m_sState = "idle";

    float m_fltSpeed = 8;

    int m_iSelectedWeapon = 0;

    std::vector<zl::TStr> m_weapons = {"knife", "handgun", "rifle", "shotgun"};
    std::vector<zl::TStr> m_states = {"idle", "meleeattack", "move", "reload", "shoot"};


public:

    void onLoadResources() override;

    void onInitializeActor() override;

    void onUpdateState() override;

    void onSFMLEvent(sf::Event &event) override;

    void nextWeapon();


};


#endif //ZERROLITESFML_PLAYER_H
