#pragma once
#include "Scene.h"
#include "Core/Player.h"
#include "Core/Button.h"
class GameScene :
    public Scene
{
public:
	GameScene(Game* game);
    // Inherited via Scene
    virtual void Init() override;
    virtual void Update(float dt, sf::RenderWindow& window) override;
    virtual void Draw(sf::RenderWindow& window) override;
	virtual void HandleEvents(const sf::Event& event) override {}
	virtual ~GameScene();
private:

	void HandleCollisions();
private:
	Player m_PacManPlayer;
	std::vector<Player*> m_GhostPlayers;
	sf::Vector2f mousePos;

	Button m_CreateBtn;
};

