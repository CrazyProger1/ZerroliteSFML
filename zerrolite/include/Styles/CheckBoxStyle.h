//
// Created by crazy on 14.01.2022.
//

#ifndef ZERROLITESFML_CHECKBOXSTYLE_H
#define ZERROLITESFML_CHECKBOXSTYLE_H

#include <SFML/Graphics.hpp>
#include "../types.h"

namespace zl {
    struct CheckBoxStyle {
    private:
        fVector m_size;
        fVector m_checkOffset = {0, 0};
        fVector m_checkHornsLenCoef = {1, 1};

        int m_checkScale = 1;
        int m_checkAngle = 90;
        float m_checkAngleRatio = 1;


        RGBAColor m_color = {100, 100, 100};
        RGBAColor m_hoverColor = {100, 100, 200};
        RGBAColor m_checkColor = {255, 0, 0};
        RGBAColor m_borderColor = {20, 0, 255};
        RGBAColor m_colorWhenChecked = {100, 255, 100};

        int m_borderWidth = 0;

        bool m_isChecked = false;

        //int m_cornerRadius = 0;
    public:
        explicit CheckBoxStyle(const fVector &size,
                               const fVector &checkOffset = {0, 0},
                               int checkScale = 1,
                               int checkAngle = 90,
                               const fVector &checkHornsLengthCoefficient = {0, 0},
                               int borderWidth = 0,
                               const RGBAColor &color = {100, 100, 100},
                               const RGBAColor &hoverColor = {100, 100, 100},
                               const RGBAColor &checkColor = {255, 0, 0},
                               const RGBAColor &colorWhenChecked = {100, 255, 100},
                               const RGBAColor &borderColor = {100, 255, 100},
                               bool checked = false


        );

        fVector getSize();

        fVector getCheckOffset();

        fVector getCheckHornsLengthCoefficient();

        int getCheckScale();

        int getCheckAngle();

        RGBAColor &getColor();

        RGBAColor &getHoverColor();

        RGBAColor &getCheckColor();

        RGBAColor &getBorderColor();

        RGBAColor &getColorWhenChecked();

        int getBorderWidth();

        bool isChecked();

    };
}


#endif //ZERROLITESFML_CHECKBOXSTYLE_H
