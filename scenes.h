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
    }


};

class GameScene : public zl::Scene {
    Player player;


    void onLoadResources() override {

    }

    void onInitializeScene() override {

        attach(&player);
    }


    void onSFMLEvent(sf::Event &event) override {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Q:
                    player.selectNextWeapon();
                    break;
                case sf::Keyboard::W:

                    break;

                case sf::Keyboard::S:

                    break;

                case sf::Keyboard::A:

                    break;

                case sf::Keyboard::D:

                    break;

                default:
                    break;
            }


        }
    }


    void onUpdateState() override {
        player.turnToMouseCursor();
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
