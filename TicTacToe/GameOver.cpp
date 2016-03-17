#include "GameOver.h"

GameOver::GameOver(StateManager &stack, sf::RenderWindow &window)
	: State(stack, window)
{
	font.loadFromFile("data/font.ttf"); 

	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setString(getString());
	text.setCharacterSize(40);
	text.setPosition({ getWindow().getSize().x / 2 - text.getLocalBounds().width / 2,
				getWindow().getSize().y / 2 - text.getGlobalBounds().height / 2 });

	click.setFont(font);
	click.setColor(sf::Color::Black);
	click.setString("Click to play again");
	click.setCharacterSize(20);
	click.setPosition({ getWindow().getSize().x / 2 - click.getLocalBounds().width / 2,
				getWindow().getSize().y - click.getGlobalBounds().height });

	opacity = 0; counter = 10;
}

GameOver::~GameOver()
{
}

void GameOver::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		popState();
		pushState(States::ID::Game);
	}
}

void GameOver::update(sf::Time dt)
{
	click.setColor(sf::Color(0, 0, 0, opacity));
	opacity += counter;

	if (opacity > 255)
	{
		opacity = 255;
		counter *= -1;
	}
	
	if (opacity < 0)
	{
		opacity = 0;
		counter *= -1;
	}
}

void GameOver::draw()
{
	getWindow().draw(text);
	getWindow().draw(click);
}
