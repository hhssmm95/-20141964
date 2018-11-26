#pragma once
#include"LoaderParams.h"
#include"Vector2D.h"
#include<SDL.h>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual Vector2D getPosition() = 0;
	virtual SDL_Rect getCollider() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

