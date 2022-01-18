//
// Created by crazy on 18.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "zerrolite/zerrolite.h"
#include <map>

class GameScene : public zl::Scene {
    zl::Player player;
    sf::Sprite sprite;


    void onLoadResources() override {
        sf::Texture texture;
        texture.loadFromFile("../resources/sprites/player/handgun/move/survivor-move_handgun_0.png");
        player.addAppearance(1, texture);
        texture.loadFromFile("../resources/sprites/player/flashlight/move/survivor-move_flashlight_0.png");
        player.addAppearance(2, texture);

    }

    void onInitializeScene() override {
        player.setSprite(&sprite);
        player.setAppearance(1);
        player.setPosition({100, 100});


        attach(&player);
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
