#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "State.h"

class GameOver final : public State
{
public:
	explicit GameOver(StateManager &stack, sf::RenderWindow &window);
	~GameOver();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	void draw() override;

private:
	sf::Font font;
	sf::Text text, click;

	int opacity, counter;
};

#endif