#pragma once
#include "Scene.h"
#include "Core/Button.h"
#include "Core/Game.h"
#include "Core/InputBox.h"
class MainMenuScene :
    public Scene
{
public:

    MainMenuScene(Game* game) : Scene(game) , m_InputBox(sf::Vector2f(128,32),  sf::Vector2f(100.f, 100.f), 32) {};
    ~MainMenuScene() {};
    virtual void Init() override;
    virtual void Update(float dt, sf::RenderWindow& window) override;
    virtual void Draw(sf::RenderWindow& window) override;
    virtual void HandleEvents(const sf::Event& event) override;
private:
    void CreateGame();
private:
    // TODO: Add menu title, background, etc.
    Button m_BtnCreateLobby;
    InputBox m_InputBox;
    sf::Font font;
    //Button m_BtnJoinLobby;
    //Game& m_Game;

};

