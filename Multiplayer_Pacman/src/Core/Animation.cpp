#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int frameCount, float animSpeed)
{

	m_FrameCount = frameCount;
	m_AnimSpeed = animSpeed;

	m_TotalTime = 0.0f;
	m_CurrentFrame = 0;

	uv_Rect.left = x;
	uv_Rect.top = y;
	
	uv_Rect.width = width;
	uv_Rect.height = height;

	for (int i = 0; i < m_FrameCount; ++i)
	{
		m_Frames.push_back(sf::IntRect(x + i * width, y, width, height));
	}
}

void Animation::Update(float& dt)
{
	m_TotalTime += dt;

	if (m_TotalTime >= m_AnimSpeed)
	{
		m_TotalTime -= m_AnimSpeed;
		m_CurrentFrame++;

		if (m_CurrentFrame >= m_FrameCount)
		{
			m_CurrentFrame = 0;
		}
	}

	uv_Rect = m_Frames[m_CurrentFrame];
}
