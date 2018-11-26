#include"Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Wall.h"

InputHandler* InputHandler::s_pInstance = 0;
CollisionManager* CollisionManager::s_pInstance = 0;

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
	if (!TheTextureManager::Instance()->load("assets/wall1.png", "wall1", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/wall2.png", "wall2", m_pRenderer))
	{
		return false;
	}
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	m_gameObjects.push_back(new Wall(new LoaderParams(400, 100, 128, 128, "wall1")));
	
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
		i != bullets.size() && bullets.size() != 0; i++)
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
		i != bullets.size() && bullets.size() != 0; i++)
	{
		bullets[i]->update();
		if (CollisionManager::Instance()->check_Collision(bullets[i]->getCollider(),
			m_gameObjects[1]->getCollider()))
		{
			bullets.erase(bullets.begin() + i);
			
			m_gameObjects[1] = new Wall(new LoaderParams(m_gameObjects[1]->getPosition().getX(),
				m_gameObjects[1]->getPosition().getY(), 128, 128, "wall2"));
		}
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
		bullets.push_back(new Bullet(new LoaderParams(m_gameObjects[0]->getPosition().getX(), 
			m_gameObjects[0]->getPosition().getY(),	64, 64, "bullet")));
	}
}