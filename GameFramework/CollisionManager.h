#pragma once
#include<SDL.h>

class CollisionManager
{
private:
	CollisionManager(){}
	~CollisionManager(){}
	static CollisionManager* s_pInstance;
public :
	static CollisionManager* Instance()
	{
		//static CollisionManager* s_pInstance;
		if (s_pInstance == 0)
		{
			s_pInstance = new CollisionManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool check_Collision(SDL_Rect A, SDL_Rect B);

	void update();
};
typedef CollisionManager TheCollisionManager;