//
// Created by crazy on 24.01.2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>

sf::CircleShape arcPart;

void draw_arc(sf::RenderWindow &window, float centerX, float centerY, float radius, int angleStart, int angleEnd,
              float width = 1) {

    if (width == 1) {
        sf::Vertex arc[angleEnd - angleStart];


        int i = 0;

        for (int angle = angleStart; angle < angleEnd; ++angle) {

            float x, y;
            double pi = 3.1415926535;
            x = centerX + std::cos(angle * (pi / 180)) * radius;
            y = centerY + std::sin(angle * (pi / 180)) * radius;

            arc[i] = sf::Vertex({x, y}, sf::Color::Red);

            i++;

        }


        window.draw(arc, angleEnd - angleStart, sf::Points);
    } else {
        for (int angle = angleStart; angle < angleEnd; ++angle) {

            float x, y;
            double pi = 3.1415926535;
            x = centerX + std::cos(angle * (pi / 180)) * radius;
            y = centerY + std::sin(angle * (pi / 180)) * radius;

            arcPart.setRadius(width / 2);

            arcPart.setPosition(x, y);

            arcPart.setOrigin(width / 2, width / 2);

            window.draw(arcPart);
        }
    }


}

std::chrono::high_resolution_clock::time_point Start;
std::chrono::high_resolution_clock::time_point End;


int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "test arc");
    int m_iFps;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Start = std::chrono::high_resolution_clock::now();

        window.clear();

        draw_arc(window, 100, 100, 30, -90, 0, 2);

        window.display();

        End = std::chrono::high_resolution_clock::now();

        m_iFps = (float) 1e9 / (float) std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start).count();
        std::cout << m_iFps << std::endl;
    }

    return 0;
}