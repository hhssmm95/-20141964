#include"Player.h"
#include<SDL.h>
#include<vector>

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
	bool m_bRunning;
	GameObject* m_go;

	Player* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

public:
	Game(){}
	~Game(){}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }


};