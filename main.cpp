#include <iostream>

#include <SFML/Graphics.hpp>

int main() {

	std::cout << "Orthofonal Dungeon\n";

	sf::RenderWindow window(sf::VideoMode(640, 480), "Orthofonal Dungeon");

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
