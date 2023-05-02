#include "Button.h"

Button::Button(std::string& filePath, const sf::Vector2f& pos, const std::function<void(void)>& callback) : m_Callback(callback)
{
	m_Texture = new sf::Texture;
	m_Texture->loadFromFile(filePath);
	m_Spr.setTexture(*m_Texture);
	m_Spr.setPosition(pos);
}

Button::~Button()
{
	m_Texture = nullptr;
	delete m_Texture;

}


void Button::Update(float dt, sf::RenderWindow& window)
{
	sf::FloatRect bounds = m_Spr.getGlobalBounds();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::FloatRect mouseRect(mousePos.x, mousePos.y, 1, 1);

	if (bounds.intersects(mouseRect))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_ButtonState = Pressed;
			OnPressed();
		}
		else
			m_ButtonState = Hovered;
	}
	else
		m_ButtonState = Default;
}
void Button::Draw(sf::RenderWindow& window)
{
	window.draw(m_Spr);
}
void Button::OnPressed()
{
	m_Callback();
}


