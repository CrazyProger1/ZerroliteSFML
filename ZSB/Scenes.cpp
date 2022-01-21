//
// Created by crazy on 20.01.2022.
//

#include "Scenes.h"

void MainMenuScene::onInitializeScene() {


    m_languageManager.loadChapter(
            "../resources/languages/" + zl::Scene::getGlobalStorage()->getStringValue("lang") + ".lang",
            "MainMenu");

    m_imgBackground.setImageFilepath("../resources/imgs/backgrounds/background1.jpg");


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

    m_imgBackground.setSize(resolution.x, resolution.y);


    m_btnNewGame.setStyle(buttonStyle);
    m_txtNewGame.setStyle(textStyle);

    m_btnLoadGame.setStyle(buttonStyle);
    m_txtLoadGame.setStyle(textStyle);

    m_btnPlayOnline.setStyle(buttonStyle);
    m_txtPlayOnline.setStyle(textStyle);

    m_btnSettings.setStyle(buttonStyle);
    m_txtSettings.setStyle(textStyle);

    m_btnAbout.setStyle(buttonStyle);
    m_txtAbout.setStyle(textStyle);

    m_btnExit.setStyle(buttonStyle);
    m_txtExit.setStyle(textStyle);


    sf::Vector2f buttonsSize = m_btnNewGame.getSize();


    m_txtNewGame.setText(m_languageManager.getTranslatedString("NewGame"));
    m_btnNewGame.setText(m_txtNewGame);

    m_txtLoadGame.setText(m_languageManager.getTranslatedString("LoadGame"));
    m_btnLoadGame.setText(m_txtLoadGame);

    m_txtPlayOnline.setText(m_languageManager.getTranslatedString("PlayOnline"));
    m_btnPlayOnline.setText(m_txtPlayOnline);

    m_txtSettings.setText(m_languageManager.getTranslatedString("Settings"));
    m_btnSettings.setText(m_txtSettings);

    m_txtAbout.setText(m_languageManager.getTranslatedString("About"));
    m_btnAbout.setText(m_txtAbout);

    m_txtExit.setText(m_languageManager.getTranslatedString("Exit"));
    m_btnExit.setText(m_txtExit);

    m_btnNewGame.setPosition((float) resolution.x - buttonsSize.x - 10,
                             resolution.y - (5 + buttonsSize.y) * 6);

    m_btnLoadGame.setPosition((float) resolution.x - buttonsSize.x - 10,
                              resolution.y - (5 + buttonsSize.y) * 5);

    m_btnPlayOnline.setPosition((float) resolution.x - buttonsSize.x - 10,
                                resolution.y - (5 + buttonsSize.y) * 4);

    m_btnSettings.setPosition((float) resolution.x - buttonsSize.x - 10,
                              resolution.y - (5 + buttonsSize.y) * 3);

    m_btnAbout.setPosition((float) resolution.x - buttonsSize.x - 10,
                           resolution.y - (5 + buttonsSize.y) * 2);

    m_btnExit.setPosition((float) resolution.x - buttonsSize.x - 10,
                          resolution.y - (5 + buttonsSize.y) * 1);


    attach(&m_imgBackground);
    attach(&m_btnNewGame);
    attach(&m_btnLoadGame);
    attach(&m_btnPlayOnline);
    attach(&m_btnSettings);
    attach(&m_btnAbout);
    attach(&m_btnExit);


}

void MainMenuScene::onUpdateState() {

    if (m_btnExit.isClicked())
        exit(0);

    if (m_btnNewGame.isClicked())
        setNewScene("OfflineGame");

}

void OfflineGameScene::onInitializeScene() {
    attach(&m_player);
}


