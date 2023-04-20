#include "GameScene.h"
#include <iostream>

GameScene::GameScene(Game* game)
	:Scene(game), m_PacManPlayer("Assets/Pac-Man.png", 0, 0, 16, 3)
{

}
void GameScene::Init()

{
	for (int i = 0; i < 4; i++)
	{
		m_GhostPlayers.push_back(new Player("Assets/ghost.png", 0, 0, 16, 2));

	}

}

void GameScene::Update(float dt, sf::RenderWindow& window)
{
	m_PacManPlayer.Update(dt);
	m_CreateBtn.Update(dt, window);
	HandleCollisions();
}

void GameScene::Draw(sf::RenderWindow& window)
{
	for (auto& g : m_GhostPlayers)
		g->Draw(window);

	m_PacManPlayer.Draw(window);
}

GameScene::~GameScene()
{
	for (auto& g : m_GhostPlayers)
	{
		delete g;

	}
	m_GhostPlayers.clear();
}

void GameScene::HandleCollisions()
{
}

