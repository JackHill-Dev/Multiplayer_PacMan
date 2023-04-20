#include "MainMenuScene.h"
#include <iostream>

void MainMenuScene::Init()
{
	m_BtnCreateLobby = Button(std::string("Assets/createBtn.png"), std::bind(&MainMenuScene::CreateGame, this));
}

void MainMenuScene::Update(float dt, sf::RenderWindow& window)
{
	m_BtnCreateLobby.Update(dt, window);
}

void MainMenuScene::Draw(sf::RenderWindow& window)
{
	m_BtnCreateLobby.Draw(window);
}

void MainMenuScene::CreateGame()
{
	// Change to lobby state
	std::cout << "Create game...\n";
	m_Game->ChangeScene(1);
}
