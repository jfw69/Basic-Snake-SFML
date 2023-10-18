#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "world.h"
#include "snake.h"
#include "window.h"
#include "Textbox.h"


class Game{
public:
	Game();
	~Game();
	void handleInput();
	void update();
	void render();

	sf::Time getElapsed();
	void restartClock();

	Window* GetWindow();

private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	World m_world;
	Snake m_snake;
	Textbox m_textBox;
};

#endif // !GAME_H_INCLUDED
