#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include <string>
class InputBox : public sf::Transformable, public sf::Drawable
{
public:
	InputBox(const sf::Vector2f& size, const sf::Vector2f& position, unsigned int fontSize);
	~InputBox();

	void HandleEvent(const sf::Event& event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void SetFont(const sf::Font& font) { m_Text.setFont(font); }
	const std::string& GetCurrentText() const { return m_currentText; }
private:
	sf::RectangleShape m_Background;
	sf::Text m_Text;
	sf::Font m_Font;
	mutable sf::RectangleShape m_Cursor;
	bool m_hasFocus;
	std::string m_currentText;
};

