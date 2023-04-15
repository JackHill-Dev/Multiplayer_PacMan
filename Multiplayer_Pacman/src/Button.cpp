#include "Button.h"

Button::Button(std::string& filePath, const std::function<void(void)>& callback) : m_Callback(callback)
{
	m_Texture = new sf::Texture;
	m_Texture->loadFromFile(filePath);
	m_Spr.setTexture(*m_Texture);
	m_Spr.setPosition(200, 320);
}

Button::~Button()
{
	m_Texture = nullptr;
	delete m_Texture;

}

void Button::OnPressed()
{
	m_ButtonState = Pressed;
	m_Callback();

}
