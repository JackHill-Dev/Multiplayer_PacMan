#pragma once
#include "Scene.h"
#include "Core/Button.h"
#include "Core/Game.h"

class MainMenuScene :
    public Scene
{
public:

    MainMenuScene(Game* game) : Scene(game) {};
    ~MainMenuScene() {};
    virtual void Init() override;
    virtual void Update(float dt, sf::RenderWindow& window) override;
    virtual void Draw(sf::RenderWindow& window) override;
private:
    void CreateGame();
private:
    // TODO: Add menu title, background, etc.
    Button m_BtnCreateLobby;
    //Button m_BtnJoinLobby;
    //Game& m_Game;

};

