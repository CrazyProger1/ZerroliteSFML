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
        str m_sImagePath;
        sf::Vector2f m_size;

        sf::Texture m_texture;
        sf::Sprite m_sprite;

    public:
        Image();

        explicit Image(const str &path);


        void initialize() override;


        void setSize(const sf::Vector2f &size);

        void setSize(float w, float h);

        void setScale(const sf::Vector2f &scale);

        void setScale(float factorX, float factorY);

        void setImageFilepath(const str &path);


        sf::Vector2f getSize();


        void draw(sf::RenderTarget &rt) override;

        void updateState() override;


    };
}


#endif //ZERROLITESFML_IMAGE_H
