//
// Created by crazy on 04.01.2022.
//

#include "../../include/GUI/Button.h"

void zl::Button::activate() {
    m_isDeactivated = false;
}

void zl::Button::deactivate() {
    m_isDeactivated = true;
}

void zl::Button::draw(sf::RenderTarget &renderTarget) {
    renderTarget.draw(mainRect);
}

zl::Button::Button() = default;
