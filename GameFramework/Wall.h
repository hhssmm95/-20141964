#pragma once
#include"SDLGameObject.h"

class Wall : public SDLGameObject
{
private:
	void handleInput();
public:
	Wall(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};