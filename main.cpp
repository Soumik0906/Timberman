#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen);

    sf::Texture textureBackground;
    textureBackground.loadFromFile("../graphics/background.png");

    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        window.draw(spriteBackground);
        window.display();
    }
    return 0;
}