#include <iostream>
#include "StateManager.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window;
	window.create({ 3*102 - 1,  3 * 102 - 1}, "Tic Tac Toe");
	StateManager state(window);
	state.pushState(States::ID::Game);

	window.setFramerateLimit(30); //reduces cpu usage

	const sf::Time m_frameTime = sf::seconds(1.f/30.f);
	sf::Clock clock;
	sf::Time passedTime = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		passedTime += elapsedTime;

		while (passedTime > m_frameTime)
		{
			passedTime -= m_frameTime;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				state.handleEvent(event);
			}
			state.update(m_frameTime);
		}

		window.clear(sf::Color(210, 210, 210)); //GREY
		state.draw();
		window.display();
	}

	return 0;
}