//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "../zerrolite/zerrolite.h"


class MainMenuScene : public zl::Scene {
    zl::Button m_btnPlay;
    zl::Text m_txtPlay;

    zl::LanguageManager m_languageManager;

    void onInitializeScene() override {


        m_languageManager.loadChapter(
                "../resources/languages/" + zl::Scene::getGlobalStorage()->getStringValue("lang") + ".lang",
                "MainMenu");

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

        sf::Vector2u resolution = getWindowResolution();

        m_btnPlay.setStyle(buttonStyle);
        m_txtPlay.setStyle(textStyle);


        sf::Vector2f buttonsSize = m_btnPlay.getSize();

        m_txtPlay.setText(m_languageManager.getTranslatedString("buttonPlay"));
        m_btnPlay.setText(m_txtPlay);

        m_btnPlay.setPosition((float) resolution.x / 2 - buttonsSize.x / 2, 100);

        attach(&m_btnPlay);

    }

    void onUpdateState() override {
        if (m_btnPlay.isClicked())
            setNewScene("GameSelection");
    }
};

class GameSelectionScene : public zl::Scene {

};


#endif //ZERROLITESFML_SCENES_H
