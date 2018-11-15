#include"TextureManager.h"

class Game
{
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
	TextureManager m_textureManager;
	bool m_bRunning;

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