//
// Created by crazy on 21.01.2022.
//

#ifndef ZERROLITESFML_ANIMATION_H
#define ZERROLITESFML_ANIMATION_H

#include <vector>
#include "../types.h"

namespace zl {
    class Animation {
    private:
        std::vector<TStr> m_appearances;

        int m_iActiveAppearance = 0;
        int m_iDuration = 0;
        int m_iDelay = 0;
        int m_iNumberOfFrames = 0;
        sf::Clock m_clock;

        bool m_bRepeat = false;


        void initialize();

    public:
        void setDuration(int milliseconds);

        void setRepeatable(bool repeat = true);

        void addAppearance(const TStr &name);

        bool already();

        TStr next();

        void reset();

    };
}


#endif //ZERROLITESFML_ANIMATION_H
