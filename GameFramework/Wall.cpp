#include "Wall.h"
#include"InputHandler.h"
#include"TextureManager.h"
#include"CollisionManager.h"
#include"Game.h"
#include <SDL.h>
Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//this->m_velocity.setX(10);
}
void Wall::draw()
{
	//SDLGameObject::draw(); // we now use SDLGameObject
	TextureManager::Instance()->draw(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, TheGame::Instance()->getRenderer());
}
void Wall::update()
{
	m_velocity.setY(0);
	SDLGameObject::update();


}
void Wall::clean()
{

}
