#include "game.h"


Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
	m_snake(m_world.getBlockSize(), &m_textBox),
	m_world(sf::Vector2u(800, 600))
{
	m_clock.restart();
	srand(time(nullptr));
	m_elapsed = 0.0f;
	m_textBox.Setup(5, 14, 350, sf::Vector2f(225, 0));
	m_textBox.Add("Seeded random number generator with: " + std::to_string(time(nullptr)));
}

Game::~Game(){}

void Game::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.getDirection() != Direction::Down) {
		m_snake.setDirction(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.getDirection() != Direction::Up) {
		m_snake.setDirction(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.getDirection() != Direction::Right) {
		m_snake.setDirction(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.getDirection() != Direction::Left) {
		m_snake.setDirction(Direction::Right);
	}
}

void Game::update(){
	m_window.Update();
	float timestep = 1.0f / m_snake.getSpeed();
	if (m_elapsed >= timestep) {
		m_snake.tick();
		m_world.Update(m_snake);
		m_elapsed -= timestep;
		if (m_snake.hasLost()) {
			m_textBox.Add("Game Over! Score: " + std::to_string((long long)m_snake.getScore()));
			m_snake.reset();
		}

	}
}

void Game::render(){

	m_window.BeginDraw();

	m_world.Render(*m_window.GetRenderWindow());
	m_snake.render(*m_window.GetRenderWindow());
	m_textBox.Render(*m_window.GetRenderWindow());

	m_window.EndDraw();
}

sf::Time Game::getElapsed(){
	return m_clock.getElapsedTime();
}

void Game::restartClock(){
	m_elapsed += m_clock.restart().asSeconds();
}

Window* Game::GetWindow(){
	return &m_window;
}

