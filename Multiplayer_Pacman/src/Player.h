#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "Animation.h"

class Player
{
public:
	Player(std::string filePath, int posX, int posY, int size, int framesPerAim);
	~Player();
	void InitAnims();
	sf::Sprite& GetSprite() { return m_Sprite; }
	const sf::FloatRect& GetGlobalBounds() const { return m_Sprite.getGlobalBounds(); }
	void Update(float& dt);
	void Draw(sf::RenderWindow& window);
	void UpdateMovement(float& dt);
	void UpdateAnimations(float& dt);
	void Decelerate(float& dt);
	enum AnimState
	{
		WalkRight,
		WalkLeft,
		WalkUp,
		WalkDown,
		Count
	};
private:
	// Player controller
	float speed = 1400;
	float deceleration = 1000;
	float m_MaxVelocity = 140;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Direction;
	// Sprite and animations
	int m_spirteSize = 0;
	int m_FramesPerAnim = 0;
	std::unique_ptr<sf::Texture> m_Texture;
	sf::Sprite m_Sprite;
	Animation m_WalkingAnim;
	AnimState m_CurrentAnimState = AnimState::WalkRight;
	std::vector<Animation> m_Anims;
};

