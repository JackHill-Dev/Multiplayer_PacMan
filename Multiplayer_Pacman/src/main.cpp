#include "Game.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Multiplayer Pac-Man");
    Game game;

    sf::Clock clock;
    float deltaTime = 0.0f;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.Update(window, deltaTime);

        window.clear();
        game.Draw(window);
        window.display();
    }

    return 0;
}