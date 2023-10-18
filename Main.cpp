#include "game.h"

int main() {
	Game game;
	while (!game.GetWindow()->IsDone()) {
		game.handleInput();
		game.update();
		game.render();
		game.restartClock();
	}
}