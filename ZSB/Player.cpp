//
// Created by crazy on 20.01.2022.
//

#include "Player.h"

namespace fs = std::experimental::filesystem;

void Player::onLoadResources() {
    sf::Texture texture;

    auto offsets = zl::FileManager::loadJson("../resources/sprites/offsets.json")["player"];
    auto animationDurations = zl::FileManager::loadJson("../resources/sprites/animation_durations.json")["player"];
    auto animationRepeatableProperty = zl::FileManager::loadJson(
            "../resources/sprites/animation_repeatable.json")["player"];
    for (auto &sWeapon: m_weapons) { // horrible loading, will be recoded!
        for (auto &sState: m_states) {


            int iMaxState = 0;

            for (; iMaxState < 1000; ++iMaxState) {
                if (!fs::exists(
                        "../resources/sprites/player/" + sWeapon + "/" + sState + "/" + std::to_string(iMaxState) +
                        ".png")) {
                    iMaxState--;
                    break;

                }
            }
            if (fs::exists("../resources/sprites/player/" + sWeapon + "/" + sState)) {
                zl::Animation animation;
                animation.setDuration(animationDurations[sWeapon][sState]);
                animation.setRepeatable(animationRepeatableProperty[sWeapon][sState]);

                for (int i = 0; i <= iMaxState; ++i) {

                    zl::TStr sAppearanceName, sFilepath;

                    sAppearanceName += sWeapon;
                    sAppearanceName += "-";
                    sAppearanceName += sState;
                    sAppearanceName += "-";
                    sAppearanceName += std::to_string(i);

                    sFilepath =
                            "../resources/sprites/player/" + sWeapon + "/" + sState + "/" + std::to_string(i) + ".png";
                    texture.loadFromFile(sFilepath);
                    addAppearance(sAppearanceName, texture,
                                  {offsets[sWeapon][0], offsets[sWeapon][1]});
                    animation.addAppearance(sAppearanceName);

                    std::cout << "Loaded: " << sFilepath << std::endl;
                }
                addAnimation(sWeapon + "-" + sState, animation);
            }
        }
    }
}

void Player::onInitializeActor() {

    setSprite(&m_sprite);
    setSpeed(m_fltSpeed);
    setPosition(200, 200);


    showAnimation(m_sSelectedWeapon + "-" + m_sState);

}


void Player::onUpdateState() {
    turnToMouseCursor();

    if (!isAnyAnimationActive()) {

        m_sState = "idle";
        showAnimation(m_sSelectedWeapon + "-" + m_sState);
    }


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
                if (m_sState == "reload")break;
                m_sState = "move";
                showAnimation(m_sSelectedWeapon + "-" + m_sState);
                break;

            case sf::Keyboard::S:
                break;

            case sf::Keyboard::R:
                m_sState = "reload";
                showAnimation(m_sSelectedWeapon + "-" + m_sState);
                break;

            default:
                break;
        }
    }

    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::W:
                if (m_sState == "reload")break;
                m_sState = "idle";
                showAnimation(m_sSelectedWeapon + "-" + m_sState);
                break;

            case sf::Keyboard::S:
                if (m_sState == "reload")break;
                m_sState = "idle";
                showAnimation(m_sSelectedWeapon + "-" + m_sState);
                break;


            default:
                break;
        }
    }
}

void Player::nextWeapon() {

}







