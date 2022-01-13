//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "zerrolite/zerrolite.h"
#include <iostream>

class About : public zl::Scene {
    void onInitializeScene() override {
    }

    void onUpdateState() override {

    }
};

class Shop : public zl::Scene {
    zl::Image testImage;

    zl::Button buttonBack;
    zl::Text textContinueCompany;

    void onInitializeScene() override {
        std::cout << "initialize" << std::endl;

        testImage.setImageFilepath("../resources/cat.jpeg");
        testImage.setScale({0.5, 0.5});

        zl::fVector imageSize = testImage.getSize();
        zl::ButtonStyle buttonStyle(
                {imageSize.x + 2, imageSize.y + 2},
                {0, 0, 0},
                {0, 255, 0},
                {0, 0},
                {0, 0},
                2,
                {0, 255, 0},
                true,
                false,
                0,
                false

        );

        buttonBack.setImage(testImage);
        buttonBack.setStyle(buttonStyle);
        buttonBack.setPosition({20, 20});
        buttonBack.setCenteringImage(true);


        attach(&buttonBack);
    }

    void onUpdateState() override {
        if (buttonBack.isClicked()) {
            setNewScene("mm");
        }
    }
};

class SinglePlayerMenu : public zl::Scene {
    zl::Text gameName;

    zl::Button buttonContinueCompany;
    zl::Text textContinueCompany;

    zl::Button buttonStartNewCompany;
    zl::Text textStartNewCompany;

    zl::Button buttonChooseMap;
    zl::Text textChooseMap;

    zl::Button buttonBack;
    zl::Text textBack;

    void onInitializeScene() override {
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
                {255, 0, 0}
        );

        gameName.setFont("../resources/fonts/consola.ttf");
        gameName.setTextColor({0, 220, 0});
        gameName.setTextHoverColor({0, 255, 0});
        gameName.setText("Snake");
        gameName.setFontSize(64);
        gameName.setPosition({10, 20});

        textContinueCompany.setText("CONTINUE");
        textStartNewCompany.setText("NEW COMPANY");
        textChooseMap.setText("CHOOSE MAP");
        textBack.setText("BACK");

        textContinueCompany.setStyle(textStyle);
        textStartNewCompany.setStyle(textStyle);
        textChooseMap.setStyle(textStyle);
        textBack.setStyle(textStyle);

        buttonContinueCompany.setText(textContinueCompany);
        buttonStartNewCompany.setText(textStartNewCompany);
        buttonChooseMap.setText(textChooseMap);
        buttonBack.setText(textBack);

        buttonContinueCompany.setPosition({10, 100});
        buttonStartNewCompany.setPosition({10, 150});
        buttonChooseMap.setPosition({10, 200});
        buttonBack.setPosition({10, 250});

        buttonContinueCompany.setStyle(buttonStyle);
        buttonStartNewCompany.setStyle(buttonStyle);
        buttonChooseMap.setStyle(buttonStyle);
        buttonBack.setStyle(buttonStyle);

        attach(&gameName);
        attach(&buttonContinueCompany);
        attach(&buttonStartNewCompany);
        attach(&buttonChooseMap);
        attach(&buttonBack);


    }

    void onUpdateState() override {
        if (buttonBack.isClicked()) {
            setNewScene("mm");
        }
    }
};

class MultiPlayerMenu : public zl::Scene {
    void onInitializeScene() override {

    }
};

class MainMenu : public zl::Scene {
    zl::Text gameName;

    zl::Button buttonPlaySinglePlayer;
    zl::Text textPlaySinglePlayer;

    zl::Button buttonPlayMultiPlayer;
    zl::Text textPlayMultiPlayer;

    zl::Button buttonShop;
    zl::Text textShop;

    zl::Button buttonAbout;
    zl::Text textAbout;

    zl::Button buttonExit;
    zl::Text textExit;


    void onInitializeScene() override {
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
                {255, 0, 0}
        );

        gameName.setFont("../resources/fonts/consola.ttf");
        gameName.setTextColor({0, 220, 0});
        gameName.setTextHoverColor({0, 255, 0});
        gameName.setText("Snake");
        gameName.setFontSize(64);
        gameName.setPosition({10, 20});

        textPlaySinglePlayer.setText("SINGLEPLAYER");
        textPlayMultiPlayer.setText("MULTIPLAYER");
        textShop.setText("SHOP");
        textAbout.setText("ABOUT");
        textExit.setText("EXIT");

        textPlaySinglePlayer.setStyle(textStyle);
        textPlayMultiPlayer.setStyle(textStyle);
        textShop.setStyle(textStyle);
        textAbout.setStyle(textStyle);
        textExit.setStyle(textStyle);

        buttonPlaySinglePlayer.setText(textPlaySinglePlayer);
        buttonPlayMultiPlayer.setText(textPlayMultiPlayer);
        buttonShop.setText(textShop);
        buttonAbout.setText(textAbout);
        buttonExit.setText(textExit);


        buttonPlaySinglePlayer.setPosition({10, 100});
        buttonPlayMultiPlayer.setPosition({10, 150});
        buttonShop.setPosition({10, 200});
        buttonAbout.setPosition({10, 250});
        buttonExit.setPosition({10, 300});

        buttonPlaySinglePlayer.setStyle(buttonStyle);
        buttonPlayMultiPlayer.setStyle(buttonStyle);
        buttonShop.setStyle(buttonStyle);
        buttonAbout.setStyle(buttonStyle);
        buttonExit.setStyle(buttonStyle);


        buttonPlayMultiPlayer.deactivate();

        attach(&gameName);
        attach(&buttonPlaySinglePlayer);
        attach(&buttonPlayMultiPlayer);
        attach(&buttonShop);
        attach(&buttonAbout);
        attach(&buttonExit);
    }

    void onUpdateState() override {
        if (gameName.isClicked()) {
            system("start https://github.com/CrazyProger1/ZerroliteSFML");
        }

        if (buttonPlaySinglePlayer.isClicked()) {
            setNewScene("spm");
        }

        if (buttonPlayMultiPlayer.isClicked()) {
            setNewScene("mpm");
        }

        if (buttonShop.isClicked()) {
            setNewScene("shop");
        }

        if (buttonAbout.isClicked()) {
            setNewScene("about");
        }

        if (buttonExit.isClicked()) {
            exit(0);
        }
    }

};

#endif //ZERROLITESFML_SCENES_H
