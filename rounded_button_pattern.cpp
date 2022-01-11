//
// Created by crazy on 04.01.2022.
//


#include <SFML/Graphics.hpp>


void drawRoundedRect(sf::RenderWindow &window,
                     sf::Vector2<float> position,
                     sf::Vector2<float> size,
                     float borderRadius,
                     sf::Color color) {
    sf::RectangleShape mainRect({size.x - borderRadius * 2, size.y});
    sf::RectangleShape sideRect({borderRadius, size.y - borderRadius * 2});
    sf::CircleShape angleCircle(borderRadius);

    angleCircle.setFillColor(color);
    mainRect.setFillColor(color);
    sideRect.setFillColor(color);

    mainRect.setPosition({position.x + borderRadius, position.y});

    angleCircle.setPosition({position.x, position.y});
    window.draw(angleCircle);

    angleCircle.setPosition({position.x + size.x - borderRadius * 2, position.y});
    window.draw(angleCircle);

    angleCircle.setPosition({position.x, position.y + size.y - borderRadius * 2});
    window.draw(angleCircle);

    angleCircle.setPosition({position.x + size.x - borderRadius * 2, position.y + size.y - borderRadius * 2});
    window.draw(angleCircle);

    sideRect.setPosition({position.x, position.y + borderRadius});
    window.draw(sideRect);

    sideRect.setPosition({position.x + size.x - borderRadius, position.y + borderRadius});
    window.draw(sideRect);

    window.draw(mainRect);
}


using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Lesson 2. kychka-pc.ru");


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
//        drawRoundedRect(window, {100, 100}, {200, 40}, 5, {250, 0, 0});
//        drawRoundedRect(window, {100, 200}, {200, 40}, 15, {0, 150, 0});

        drawRoundedRect(window, {99, 399}, {202, 42}, 10, {100, 0, 100});
        drawRoundedRect(window, {100, 400}, {200, 40}, 9, {250, 0, 0});
        window.display();
    }

    return 0;
}