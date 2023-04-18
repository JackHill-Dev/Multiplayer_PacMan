#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Player.h"


class Game
{
public:
	Game();
	~Game();
	void Update(sf::RenderWindow& window, float& dt);
	void Draw(sf::RenderWindow& RenderWindow);
private:
	void HandleCollisions();
	void CreateGame();
private:
	Player m_PacManPlayer;
	std::vector<Player*> m_GhostPlayers;
	sf::Vector2f mousePos;

	Button m_CreateBtn;
};
