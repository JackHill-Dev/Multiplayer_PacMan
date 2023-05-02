#include "MainMenuScene.h"
#include <iostream>
#include <SFML/Graphics/Font.hpp>
void MainMenuScene::Init()
{
	m_BtnCreateLobby = Button(std::string("Assets/createBtn.png"), sf::Vector2f(200,300), std::bind(&MainMenuScene::CreateGame, this));
	m_BtnGetInput = Button(std::string("Assets/inputBtn.png"),sf::Vector2f(200, 600), std::bind(&MainMenuScene::GetInput, this));
	font.loadFromFile("Assets/Silver.ttf");
	m_InputBox.SetFont(font);;
}

void MainMenuScene::Update(float dt, sf::RenderWindow& window)
{
	m_BtnCreateLobby.Update(dt, window);
	m_BtnGetInput.Update(dt, window);
}

void MainMenuScene::Draw(sf::RenderWindow& window)
{
	m_BtnCreateLobby.Draw(window);
	m_BtnGetInput.Draw(window);
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

const std::string& MainMenuScene::GetInput()
{
	return m_InputBox.GetCurrentText();
}
