#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Timber!!!", sf::Style::Fullscreen);

    sf::Texture textureBackground;
    textureBackground.loadFromFile("../graphics/background.png");

    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    sf::Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");
    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    sf::Texture textureBee;
    textureBee.loadFromFile("../graphics/bee.png");
    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    bool beeActive = false;

    float beeSpeed = 0.0f;


    sf::Texture textureCloud;
    textureCloud.loadFromFile("../graphics/cloud.png");

    sf::Sprite spriteCloud1, spriteCloud2, spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    sf::Clock clock;

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        window.clear();

        sf::Time dt = clock.restart();

        if (!beeActive) {
            srand(int(time(0)));
            beeSpeed = (rand() % 200) + 200;

            srand(int(time(0)) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        } else {
            spriteBee.setPosition(
                spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                spriteBee.getPosition().y
            );
            
            if (spriteBee.getPosition().x < -100) {
                beeActive = false;
            }
        }

        window.draw(spriteBackground);

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        

        window.draw(spriteTree);

        window.draw(spriteBee);

        window.display();
    }

    return 0;
}
