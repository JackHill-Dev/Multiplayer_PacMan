#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Player.h"
#include "Scenes/Scene.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainMenuScene.h"
#include <stack>
#include <memory>

class MainMenuScene;
class GameScene;

class Game
{
public:
	Game();
	~Game();
	void Run();
	std::shared_ptr<Scene> GetActiveScene();
	void ChangeScene(int sceneNo);
private:
	void PushState(std::shared_ptr<Scene> state);
	void PopState();
private:
	std::vector<Scene*> m_Scenes;
	int currentScene = 0;
	// Keep references to the scenes so they keep their previous states rather than creating a new one each time
	// Scenes
	// Mainmenu
	//std::shared_ptr<Scene> m_MainMenu;
	// Lobby
	// Game
	//std::shared_ptr <Scene> m_GameScene;
};
