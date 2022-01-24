//
// Created by crazy on 21.01.2022.
//

#include <iostream>
#include "../../include/Core/Animation.h"

void zl::Animation::initialize() {
    m_clock.restart();

    if (m_iNumberOfFrames > 0)
        m_iDelay = m_iDuration / m_iNumberOfFrames;


}


void zl::Animation::setDuration(int milliseconds) {
    m_iDuration = milliseconds;
    initialize();
}

void zl::Animation::setRepeatable(bool repeat) {
    m_bRepeat = repeat;
}


void zl::Animation::addAppearance(const zl::TStr &name) {
    m_appearances.emplace_back(name);
    m_iNumberOfFrames++;
    initialize();


}

bool zl::Animation::already() {
    if (m_clock.getElapsedTime().asMilliseconds() >= (m_iActiveAppearance + 1) * m_iDelay) {
        return true;
    }

    return false;
}

zl::TStr zl::Animation::next() {
    m_iActiveAppearance++;

    if (m_iActiveAppearance == m_appearances.size() && m_bRepeat)
        reset();
    else if (m_iActiveAppearance == m_appearances.size() && !m_bRepeat)
        return "end";

    return m_appearances[m_iActiveAppearance];
}

void zl::Animation::reset() {
    m_iActiveAppearance = 0;
    initialize();
}







