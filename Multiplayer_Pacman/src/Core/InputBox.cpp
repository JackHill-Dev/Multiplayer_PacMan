#include "InputBox.h"

InputBox::InputBox(const sf::Vector2f& size, const sf::Vector2f& position, unsigned int fontSize)
{
	m_Background.setSize(size);
	m_Background.setPosition(position);
	m_Background.setFillColor(sf::Color::White);
	m_Background.setOutlineThickness(2.f);
	m_Background.setOutlineColor(sf::Color::Black);

	m_Text.setCharacterSize(fontSize);
	m_Text.setPosition(position);
	m_Text.setFillColor(sf::Color::Black);
	

	m_Cursor.setSize({ 2.f, static_cast<float>(fontSize) });
	m_Cursor.setFillColor(sf::Color::Black);

	m_hasFocus = false;
}

InputBox::~InputBox()
{
}

void InputBox::HandleEvent(const sf::Event& event)
{

	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::FloatRect bounds = m_Background.getGlobalBounds();
			if (bounds.contains(event.mouseButton.x, event.mouseButton.y))
				m_hasFocus = true;
			else
				m_hasFocus = false;
		}
		break;

	case sf::Event::TextEntered:
		if (m_hasFocus)
		{
			if (event.text.unicode < 128 && event.text.unicode != '\r' && event.text.unicode != '\b')
			{
				m_currentText += static_cast<char>(event.text.unicode);
			}
		}
		break;
	case sf::Event::KeyPressed:
	
		if (m_hasFocus)
		{
			if (event.key.code == sf::Keyboard::BackSpace && !m_currentText.empty())
			{
				m_currentText.pop_back();
				m_Text.setString(m_currentText);
			}
		}
		break;
	
	default: break;
	}

	m_Text.setString(m_currentText);
}

void InputBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_Background, states);
	
	target.draw(m_Text, states);

	if (m_hasFocus)
	{
		sf::FloatRect bounds = m_Text.getGlobalBounds();
		sf::Vector2f cursorPos = { bounds.left + bounds.width, bounds.top + bounds.height };
		m_Cursor.setPosition(cursorPos);
		target.draw(m_Cursor, states);
	}
}
