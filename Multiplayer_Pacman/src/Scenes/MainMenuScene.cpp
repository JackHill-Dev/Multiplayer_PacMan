#include "MainMenuScene.h"
#include <iostream>
#include <SFML/Graphics/Font.hpp>
void MainMenuScene::Init()
{
	m_BtnCreateLobby = Button(std::string("Assets/createBtn.png"), std::bind(&MainMenuScene::CreateGame, this));
	font.loadFromFile("Assets/Silver.ttf");
	m_InputBox.SetFont(font);;
}

void MainMenuScene::Update(float dt, sf::RenderWindow& window)
{
	m_BtnCreateLobby.Update(dt, window);
}

void MainMenuScene::Draw(sf::RenderWindow& window)
{
	m_BtnCreateLobby.Draw(window);
	window.draw(m_InputBox);
}

void MainMenuScene::HandleEvents(const sf::Event& event)
{
	m_InputBox.HandleEvent(event);
}

void MainMenuScene::CreateGame()
{
	// Change to lobby state
	std::cout << "Create game...\n";
	m_Game->ChangeScene(1);
}
