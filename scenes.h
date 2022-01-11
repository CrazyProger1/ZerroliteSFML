//
// Created by crazy on 07.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "zerrolite/zerrolite.h"
#include <iostream>


class SinglePlayerMenu : public zl::Scene {
    zl::Button btn;
    zl::Text txt;


    void onInitializeScene() override {
        btn.setSize({200, 100});
        btn.setPosition({100, 100});
        btn.setCornerRadius(20);
        btn.setBorderWidth(40);
        txt.setText("HELLO WORLD!");
        txt.setFontSize(20);
        btn.setCenteringText(true);
        txt.setTextColor({200, 250, 0});

        btn.setText(txt);
        attach(&btn);
    }
};

class MultiPlayerMenu : public zl::Scene {
    void onInitializeScene() override {

    }
};

class MainMenu : public zl::Scene {
    zl::Text testText;


    void onInitializeScene() override {
        testText.setText("hello");
        testText.setPosition({100, 200});
        testText.setFontSize(20);
        testText.setUnderlineWidth(1);
        testText.setTextHoverColor({250, 0, 100});

        attach(&testText);
    }

    void onUpdateState() override {
        if (testText.isHovered()) {
            std::cout << "hovered" << std::endl;
        }
        if (testText.isClicked()) {
            setNewScene("spm");
        }
    }

};

#endif //ZERROLITESFML_SCENES_H
