#ifndef SNAKE_H_INCLUDED
#define	SNAKE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include "Textbox.h"

struct snakeSegment {
	snakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

using snakeContainer = std::vector<snakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int blockSize, Textbox* log);
	~Snake();

	//methods getters and setters
	void setDirction(Direction dir);
	Direction getDirection();
	int getSpeed();
	sf::Vector2i getPosition();
	int getLives();
	int getScore();
	void increaseScore();
	bool hasLost();

	void lose();
	void toggleLost();

	Direction getPhycisalDirection();

	void extend();
	void reset();

	void move();
	void tick();
	void cut(int segments);
	void render(sf::RenderWindow& window);

private:
	void checkCollison();

	snakeContainer m_snakeBody;
	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;
	sf::RectangleShape m_bodyRect;
	Textbox* m_log;
};

#endif // !SNAKE_H_INCLUDED

