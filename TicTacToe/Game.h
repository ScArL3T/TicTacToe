#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "AI.h"

class Game final : public State
{
public:
	explicit Game(StateManager &stack, sf::RenderWindow &window);
	~Game();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	void draw() override;

private:
	Board board;
	AI ai;
};

#endif