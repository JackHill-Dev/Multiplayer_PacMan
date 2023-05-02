#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>


class Button
{
public:
	enum State
	{
		Default,
		Hovered,
		Pressed
	};

	/// <summary>
	//	Use std bind and reference to instance that contains the function you are binding
	//	m_CreateBtn = Button(std::string("Assets/createBtn.png"), std::bind(&Game::CreateGame, this));
	/// </summary>
	/// <param name="callback"></param>
	Button(std::string& filePath, const sf::Vector2f& pos, const std::function<void(void)>& callback);
	Button() { m_Texture = new sf::Texture; };
	~Button();
	sf::Sprite& GetSprite() { return m_Spr; }
	void OnPressed();
	void Update(float dt, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
private:
	sf::Sprite m_Spr;
	sf::Texture* m_Texture;
	State m_ButtonState = Default;
	std::function<void()> m_Callback;
};

