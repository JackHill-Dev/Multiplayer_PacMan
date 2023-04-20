#include "Player.h"



Player::Player(std::string filePath, int posX, int posY, int size, int framesPerAim)
{
	m_spirteSize = size;
	m_FramesPerAnim = framesPerAim;
	sf::IntRect rect({ posX, posY }, { size,size });
	m_Texture = std::make_unique<sf::Texture>();
	m_Texture->loadFromFile(filePath);
	m_Sprite.setTexture(*m_Texture);
	m_Sprite.setTextureRect(rect);
	m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
	m_Sprite.setPosition(640, 320);
	m_Sprite.setScale(2, 2); // scaling up from a 16bit spritesheet

	InitAnims();
}


Player::~Player()
{

}

void Player::InitAnims()
{
	m_Anims.reserve(AnimState::Count);

	for(int i = 0; i < AnimState::Count; i++)
		m_Anims.push_back(Animation(0, i * m_spirteSize, m_spirteSize, m_spirteSize, m_FramesPerAnim, 0.2f));

}


void Player::Update(float& dt)
{
	UpdateMovement(dt);
	
	UpdateAnimations(dt);
	Decelerate(dt);
	m_Sprite.move(m_Velocity * dt);
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);

}
void Player::UpdateMovement(float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Velocity.x -= speed;
		m_CurrentAnimState = AnimState::WalkLeft;
		m_Direction = sf::Vector2f(-1, 0);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Velocity.x += speed;
		m_CurrentAnimState = AnimState::WalkRight;
		m_Direction = sf::Vector2f(1, 0);
	}

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Velocity.y -= speed;
		m_CurrentAnimState = AnimState::WalkUp;
		m_Direction = sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Velocity.y += speed;
		m_CurrentAnimState = AnimState::WalkDown;
		m_Direction = sf::Vector2f(0, 1);
	}


}


void Player::UpdateAnimations(float& dt)
{
	m_Anims[m_CurrentAnimState].Update(dt);
	m_Sprite.setTextureRect(m_Anims[m_CurrentAnimState].uv_Rect);
}

void Player::Decelerate(float& dt)
{
	if (m_Velocity.x > 0.0f)
	{

		if (m_Velocity.x > m_MaxVelocity)
			m_Velocity.x = m_MaxVelocity;

		m_Velocity.x -= deceleration * dt;
		if (m_Velocity.x < 0.0f)
			m_Velocity.x = 0;
	}
	else if (m_Velocity.x < 0.0f)
	{

		if (m_Velocity.x < -m_MaxVelocity)
			m_Velocity.x = -m_MaxVelocity;

		m_Velocity.x += deceleration * dt;
		if (m_Velocity.x > 0.0f)
			m_Velocity.x = 0;
	}

	if (m_Velocity.y > 0.0f)
	{

		if (m_Velocity.y > m_MaxVelocity)
			m_Velocity.y = m_MaxVelocity;

		m_Velocity.y -= deceleration * dt;
		if (m_Velocity.y < 0.0f)
			m_Velocity.y = 0;
	}
	else if (m_Velocity.y < 0.0f)
	{

		if (m_Velocity.y < -m_MaxVelocity)
			m_Velocity.y = -m_MaxVelocity;

		m_Velocity.y += deceleration * dt;
		if (m_Velocity.y > 0.0f)
			m_Velocity.y = 0;
	}
}
