#include <iostream>
#include "zerrolite/include/GameCore.h"
#include "zerrolite/include/Scene.h"
#include <SFML/Graphics.hpp>
#include "zerrolite/include/Entity.h"
#include "zerrolite/include/GUI/Button.h"
#include "zerrolite/include/GUI/Text.h"

class Game : public zl::GameCore {

};

class SinglePlayer : public zl::Scene {
    void initializeEntities() override {

    }
};

class MainMenu : public zl::Scene {
    zl::Text text;
    zl::Button button;
    zl::Text tfb;


    void initializeEntities() override {
        text.setPosition({100, 100});
        text.setFont("../resources/fonts/lucon.ttf");
        text.setText("hello");
        text.setTextColor({200, 0, 0});
        text.setFontSize(64);
        text.setUnderlineWidth(2);
        text.setUnderlineOffset(10);
        attach(text);


        tfb.setFont("../resources/fonts/lucon.ttf");
        tfb.setText("MY BUTTON");
        tfb.setTextColor({0, 0, 255});
        tfb.setFontSize(20);


        button.setPosition({400, 100});
        button.setSize({150, 40});
        button.setBorderWidth(2);
        button.setBorderColor({255, 0, 0});
        button.setText(tfb);
        button.setHoverColor({30, 150, 0});
        button.setCenterText();
        attach(button);


    }

    void updateState() override {
        if (text.isClicked())
            std::cerr << "link clicked" << std::endl;

        if (button.isClicked())
            std::cerr << "button clicked" << std::endl;

    }


};


int main() {

    sf::RenderWindow window({640, 480}, "hello world");

    Game game;

    MainMenu mainMenuScene;

    game.setMainWindow(&window);
    game.setActiveScene(&mainMenuScene);

    game.run();

    return 0;
}


