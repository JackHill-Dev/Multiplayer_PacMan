#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

class InputBox
{
public:
	InputBox(sf::Font& font, unsigned int fontSize);
	~InputBox();

	void Update(float dt);
	void Draw(sf::RenderTarget& target);
private:
	sf::Text m_Text;
	sf::RectangleShape m_Box;
	bool m_selected;
};

