#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
class Game;

class Scene
{
public:
	Scene(Game* game) : m_Game(game) {};
	virtual void Init() = 0;
	virtual void Update(float dt, sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
protected:
	std::shared_ptr<Game> m_Game;
};