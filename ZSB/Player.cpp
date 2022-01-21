//
// Created by crazy on 20.01.2022.
//

#include "Player.h"


void Player::onLoadResources() {
    sf::Texture texture;

    auto offsets = zl::FileManager::loadJson("../resources/sprites/offsets.json")["player"];

    for (auto &file: std::experimental::filesystem::recursive_directory_iterator("../resources/sprites/player/")) {


        if (std::experimental::filesystem::is_regular_file(file)) {

            zl::TStr sFilepath = file.path().string();
            sFilepath = sFilepath.substr(28, sFilepath.size() - 28);
            sFilepath.replace(sFilepath.find(".png"), 4, "");

            texture.loadFromFile(file.path().string());

            zl::TStr sWeaponName = sFilepath.substr(0, sFilepath.find('\\'));

            addAppearance(sFilepath, texture, {offsets[sWeaponName][0], offsets[sWeaponName][1]});

            std::cout << "Loaded: " << sFilepath << std::endl;
        }
    }
}

void Player::onInitializeActor() {
    setAppearance(m_sSelectedWeapon + "\\" + m_sAction + "\\" + std::to_string(m_iAnimationState));

    setSprite(&m_sprite);
    setSpeed(m_fltSpeed);
    setPosition(200, 200);

    zl::Animation animation;


    animation.setDuration(1500);


    animation.addAppearance("shotgun\\reload\\0");
    animation.addAppearance("shotgun\\reload\\1");
    animation.addAppearance("shotgun\\reload\\2");
    animation.addAppearance("shotgun\\reload\\3");
    animation.addAppearance("shotgun\\reload\\4");
    animation.addAppearance("shotgun\\reload\\5");
    animation.addAppearance("shotgun\\reload\\6");
    animation.addAppearance("shotgun\\reload\\7");
    animation.addAppearance("shotgun\\reload\\8");
    animation.addAppearance("shotgun\\reload\\9");
    animation.addAppearance("shotgun\\reload\\10");
    animation.addAppearance("shotgun\\reload\\11");
    animation.addAppearance("shotgun\\reload\\12");
    animation.addAppearance("shotgun\\reload\\13");
    animation.addAppearance("shotgun\\reload\\14");
    animation.addAppearance("shotgun\\reload\\15");
    animation.addAppearance("shotgun\\reload\\16");
    animation.addAppearance("shotgun\\reload\\17");
    animation.addAppearance("shotgun\\reload\\18");
    animation.addAppearance("shotgun\\reload\\19");


    zl::Animation animation2;

    animation2.setDuration(2000);
    animation2.setRepeatable(true);

    animation2.addAppearance("shotgun\\idle\\0");
    animation2.addAppearance("shotgun\\idle\\1");
    animation2.addAppearance("shotgun\\idle\\2");
    animation2.addAppearance("shotgun\\idle\\3");
    animation2.addAppearance("shotgun\\idle\\4");
    animation2.addAppearance("shotgun\\idle\\5");
    animation2.addAppearance("shotgun\\idle\\6");
    animation2.addAppearance("shotgun\\idle\\7");
    animation2.addAppearance("shotgun\\idle\\8");
    animation2.addAppearance("shotgun\\idle\\9");
    animation2.addAppearance("shotgun\\idle\\10");
    animation2.addAppearance("shotgun\\idle\\11");
    animation2.addAppearance("shotgun\\idle\\12");
    animation2.addAppearance("shotgun\\idle\\13");
    animation2.addAppearance("shotgun\\idle\\14");
    animation2.addAppearance("shotgun\\idle\\15");
    animation2.addAppearance("shotgun\\idle\\16");
    animation2.addAppearance("shotgun\\idle\\17");
    animation2.addAppearance("shotgun\\idle\\18");
    animation2.addAppearance("shotgun\\idle\\19");
//
//
    addAnimation("shotgun\\reload", animation);
    addAnimation("shotgun\\idle", animation2);

//
    showAnimation("shotgun\\idle");

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

void Player::onSFMLEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Q:
                nextWeapon();
                break;

            case sf::Keyboard::W:

                m_sAction = "move";
                break;

            case sf::Keyboard::S:
                m_sAction = "move";
                break;

            case sf::Keyboard::R:
                m_sAction = "reload";
                showAnimation("shotgun\\" + m_sAction);
                break;

            default:
                break;
        }
    }

    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::W:
                if (m_sAction == "reload")break;
                m_sAction = "idle";
                break;

            case sf::Keyboard::S:
                if (m_sAction == "reload")break;
                m_sAction = "idle";
                break;


            default:
                break;
        }
    }
}

void Player::nextWeapon() {
    m_iSelectedWeapon++;
    if (m_iSelectedWeapon == 4) m_iSelectedWeapon = 0;

    m_sSelectedWeapon = m_weapons[m_iSelectedWeapon];

}







