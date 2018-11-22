#include "Bullet.h"
#include"InputHandler.h"
#include"TextureManager.h"
#include"Game.h"
#include <SDL.h>
Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	this->m_velocity.setX(10);
}
void Bullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Bullet::update()
{
	m_velocity.setY(0);

	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());

}
void Bullet::clean()
{

}

void Bullet::handleInput()
{
	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;*/
}
