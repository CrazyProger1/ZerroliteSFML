//
// Created by crazy on 20.01.2022.
//

#include "Player.h"

void Player::onInitializeActor() {
    sf::Texture texture;
    texture.loadFromFile("../resources/sprites/player/rifle/idle/0.png");
    addAppearance(1, texture, {-61, 17});
    addAppearance(100, texture);
    addAppearance(200, texture);

    setAppearance(1);


    setSprite(&m_sprite);
    setSpeed(m_fltSpeed);
    setPosition(200, 200);

//    showOrigin();
}

void Player::onUpdateState() {
    turnToMouseCursor();

    for (auto &iKey: getPressedKeys()) {
        switch (iKey) {
            case sf::Keyboard::W:
                if (std::find(getPressedKeys().begin(), getPressedKeys().end(), sf::Keyboard::LShift) !=
                    getPressedKeys().end())
                    moveForward(1.5);
                else {
                    moveForward();
                }
                break;

            case sf::Keyboard::S:
                moveBack();
                break;

            case sf::Keyboard::A:
                moveLeft();
                break;

            case sf::Keyboard::D:
                moveRight();
                break;

            default:
                break;
        }

    }
}





