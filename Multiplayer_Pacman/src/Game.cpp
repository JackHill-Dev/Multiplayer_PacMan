#include "Game.h"
#include <functional>
#include <string>
Game::Game()
{

}

void Game::Update(sf::RenderWindow& window, float& dt)
{
	mousePos = window.mapPixelToCoords( sf::Mouse::getPosition(window));
	cursor.SetPos(mousePos);
	m_Player.Update(dt);
	

	
	HandleCollisions();
}

void Game::Draw(sf::RenderWindow& RenderWindow)
{
	RenderWindow.draw(cursor.GetSprite());
	m_Player.Draw(RenderWindow);
}

void Game::HandleCollisions()
{
}


