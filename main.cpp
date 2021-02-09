#include <iostream>

#include <SFML/Graphics.hpp>

#include "game_box/bitmap.h"

int main() {

	std::cout << "Orthofonal Dungeon\n";

	sf::RenderWindow window(sf::VideoMode(640, 480), "Orthofonal Dungeon");

    box::bitmap_t<> b({ 100,100 });
    b.clear();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    system("pause");
}
