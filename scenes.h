//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "zerrolite/zerrolite.h"
#include <map>

class Player : public zl::Player {
    int selectedWeapon = 0;
    sf::Sprite sprite;

    float speed = 8;

    std::vector<int> pressedButtons;

public:

    void selectNextWeapon() {
        selectedWeapon++;
        if (selectedWeapon == 4) selectedWeapon = 0;
        setAppearance(selectedWeapon);
    }

    void onLoadResources() override {
        sf::Texture texture;
        texture.loadFromFile("../resources/sprites/player/knife/move/survivor-move_knife_0.png");
        addAppearance(0, texture);
        texture.loadFromFile("../resources/sprites/player/handgun/move/survivor-move_handgun_0.png");
        addAppearance(1, texture);
        texture.loadFromFile("../resources/sprites/player/rifle/move/survivor-move_rifle_0.png");
        addAppearance(2, texture);
        texture.loadFromFile("../resources/sprites/player/shotgun/move/survivor-move_shotgun_0.png");
        addAppearance(3, texture);
    }

    void onInitializeActor() override {
        setSprite(&sprite);
        setAppearance(selectedWeapon);
        setPosition({100, 100});
        setSpeed(speed);
    }

    void onUpdateState() override {
        turnToMouseCursor();

        for (auto keyCode: pressedButtons) {
            if (keyCode == sf::Keyboard::W) {
                moveForward();
                break;
            } else if (keyCode == sf::Keyboard::S) {
                moveBack();
                break;
            }
        }
    }


    void onSFMLEvent(sf::Event &event) override {
        if (event.type == sf::Event::KeyPressed) {
            pressedButtons.emplace_back(event.key.code);
            switch (event.key.code) {
                case sf::Keyboard::Q:
                    selectNextWeapon();
                default:
                    break;


            }
        } else if (event.type == sf::Event::KeyReleased) {
            pressedButtons.erase(std::remove(pressedButtons.begin(), pressedButtons.end(), event.key.code),
                                 pressedButtons.end());
        }
    }


};

class GameScene : public zl::Scene {
    Player player;

    void onInitializeScene() override {
        attach(&player);
    }


};


class MenuScene : public zl::Scene {
    zl::Button btnPlay;
    zl::Text txtPlay;


    void onInitializeScene() override {
        zl::uVector resolution = getParentWindow()->getSize();

        zl::ButtonStyle buttonStyle(
                {220, 40},
                {0, 0, 0},
                {0, 255, 0},
                {0, 0},
                {0, 0},
                1,
                {0, 255, 0},
                true,
                false,
                10,
                false
        );

        zl::TextStyle textStyle(
                "../resources/fonts/consola.ttf",
                0,
                20,
                5,
                0,
                {0, 255, 0},
                {0, 0, 0},
                {0, 0, 0}
        );

        txtPlay.setText("Play");
        txtPlay.setFont("../resources/fonts/lucon.ttf");
        txtPlay.setStyle(textStyle);
        btnPlay.setStyle(buttonStyle);
        btnPlay.setText(txtPlay);
        btnPlay.setPosition({(float) resolution.x / 2 - 110, (float) resolution.y / 2 - 20});
        attach(&btnPlay);

    }

    void onUpdateState() override {
        if (btnPlay.isClicked()) {
            setNewScene("game");
        }
    }

};

#endif //ZERROLITESFML_SCENES_H
