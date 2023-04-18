#include "Game.h"
#include <functional>
#include <string>
#include <iostream>
Game::Game()
	: m_PacManPlayer("Assets/Pac-Man.png", 0,0, 16, 3)
{
	for (int i = 0; i < 4; i++)
	{
		m_GhostPlayers.push_back( new Player("Assets/ghost.png", 0, 0, 16, 2));

	}

	m_CreateBtn = Button(std::string("Assets/createBtn.png"), std::bind(&Game::CreateGame, this));
}

Game::~Game()
{
	for (auto& g : m_GhostPlayers)
	{
		delete g;
		
	}
	m_GhostPlayers.clear();
}

void Game::Update(sf::RenderWindow& window, float& dt)
{
	m_PacManPlayer.Update(dt);
	m_CreateBtn.Update(dt, window);
	HandleCollisions();
}

void Game::Draw(sf::RenderWindow& RenderWindow)
{
	for (auto& g : m_GhostPlayers)
		g->Draw(RenderWindow);

	m_PacManPlayer.Draw(RenderWindow);
	m_CreateBtn.Draw(RenderWindow);
}

void Game::HandleCollisions()
{

}

void Game::CreateGame()
{
	std::cout << "Creating game...\n";
}


