//
// Created by crazy on 20.01.2022.
//

#ifndef ZERROLITESFML_SCENES_H
#define ZERROLITESFML_SCENES_H

#include "../zerrolite/zerrolite.h"
#include "./Player.h"

class MainMenuScene : public zl::Scene {
    zl::Button m_btnNewGame;
    zl::Text m_txtNewGame;

    zl::Button m_btnLoadGame;
    zl::Text m_txtLoadGame;

    zl::Button m_btnPlayOnline;
    zl::Text m_txtPlayOnline;

    zl::Button m_btnSettings;
    zl::Text m_txtSettings;

    zl::Button m_btnAbout;
    zl::Text m_txtAbout;

    zl::Button m_btnExit;
    zl::Text m_txtExit;


    zl::Image m_imgBackground;

    zl::LanguageManager m_languageManager;

    void onInitializeScene() override;

    void onUpdateState() override;
};

class OfflineGameScene : public zl::Scene {
    Player m_player;


    void onInitializeScene() override;

};


#endif //ZERROLITESFML_SCENES_H

