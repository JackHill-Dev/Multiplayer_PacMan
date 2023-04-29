#include "InputBox.h"




InputBox::InputBox(sf::Font& font, unsigned int fontSize)
	: m_Text("", font, fontSize), m_selected(false)
{
    // Set default text color
    m_Text.setFillColor(sf::Color::White);

    // Set default box properties
    m_Box.setFillColor(sf::Color::Transparent);
    m_Box.setOutlineThickness(2.f);
    m_Box.setOutlineColor(sf::Color::White);
}

InputBox::~InputBox()
{
}

void InputBox::HandleEvent(const sf::Event& event)
{
}

void InputBox::Draw(sf::RenderTarget& target)
{
}
