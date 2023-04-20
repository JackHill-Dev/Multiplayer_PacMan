#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation() = default;
	Animation(int x, int y,int width, int height, int frameCount, float animSpeed);
	
	void Update(float& dt);
public:
	sf::IntRect uv_Rect;
private:
	std::vector<sf::IntRect> m_Frames;
	int m_FrameCount = 0.0f;
	int m_CurrentFrame = 0;
	float m_TotalTime = 0;
	float m_AnimSpeed = 0;
};