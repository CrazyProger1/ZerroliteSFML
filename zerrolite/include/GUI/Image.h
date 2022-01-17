//
// Created by crazy on 12.01.2022.
//

#ifndef ZERROLITESFML_IMAGE_H
#define ZERROLITESFML_IMAGE_H

#include "../Core/Entity.h"
#include <string>
#include <utility>
#include <iostream>

namespace zl {
    class Image : public Entity {
    private:
        str m_imagePath;
        fVector m_size;

        sf::Texture m_texture;
        sf::Sprite m_sprite;

        void init();

    public:
        Image();

        explicit Image(const str &path);

        void initialize() override;

        void setSize(const zl::fVector &size);

        void setScale(const zl::fVector &scale);

        void setImageFilepath(const str &path);

        void draw(sf::RenderTarget &rt) override;

        void updateState() override;

        fVector getSize();
    };
}


#endif //ZERROLITESFML_IMAGE_H
