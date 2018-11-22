#include"Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Enemy.h"
#include "Bullet.h"

InputHandler* InputHandler::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;
	}
	else {
		return false;
	}

	
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/bullet.png", "bullet", m_pRenderer))
	{
		return false;
	}
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	for (std::vector<GameObject*>::size_type i = 0;
		i != bullets.size(); i++)
	{
		bullets[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	for (std::vector<GameObject*>::size_type i = 0;
		i != bullets.size(); i++)
	{
		bullets[i]->update();
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	clean();
}

void Game::handleEvents()
{
	
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		bullets.push_back(new Bullet(new LoaderParams(105, 100, 64, 64, "bullet")));
	}
}