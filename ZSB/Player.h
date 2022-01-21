//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_PLAYER_H
#define ZERROLITESFML_PLAYER_H

#include "../zerrolite/zerrolite.h"

class Player : public zl::MainActor {
private:
    sf::Sprite m_sprite;

    int m_iSelectedWeapon = 3;

    float m_fltSpeed = 8;
public:
    void onInitializeActor() override;

    void onUpdateState() override;



};


#endif //ZERROLITESFML_PLAYER_H
