#include "Game.h"
#include <functional>
#include <string>
#include <iostream>
Game::Game()
{
	m_Scenes.push_back(new MainMenuScene(this));
	m_Scenes.push_back(new GameScene(this));
}

Game::~Game()
{

}

void Game::Run()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Multiplayer Pac-Man");

	sf::Clock clock;
	float deltaTime = 0.0f;


	for (auto& scene : m_Scenes)
		scene->Init();

	ChangeScene(0);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			m_Scenes[currentScene]->HandleEvents(event);
		}

		// Network handling
		if (isHost)
		{
			// Start listening for clients
			// Set the host player as ID #1
			// Start a send/recieve thread for each connected client
		}
		if (isClient)
		{
			// Connect to host
			// Set the ID to currentNoPlayers++
			// Start a send/recieve thread
		}

		// Game logic
		m_Scenes[currentScene]->Update(deltaTime, window);
		// Game render
		window.clear();
		m_Scenes[currentScene]->Draw(window);
		window.display();
	}
}

void Game::ChangeScene(int sceneNo)
{
	if (sceneNo != currentScene)
		currentScene = sceneNo;
}




