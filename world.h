#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "snake.h"

class World{
public:
	World(sf::Vector2u windSize);
	~World();

	int getBlockSize();
	
	void respawnApple();

	void Update(Snake& player);
	void Render(sf::RenderWindow& window);

private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;
	int m_blockSize;

	sf::CircleShape m_appleShape;
	sf::RectangleShape m_bounds[4];
};
#endif // !WORLD_H_INCLUDED
