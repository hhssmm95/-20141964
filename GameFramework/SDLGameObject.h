#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual Vector2D getPosition();
	virtual SDL_Rect getCollider();
	
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
	SDL_Rect m_collider;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};
