#include "State.h"
#include "StateManager.h"

std::string State::gameover = "";

State::State(StateManager &stack, sf::RenderWindow &window)
	: stack(stack)
	, window(window)
	, active(true)
{
}

bool State::isActive()
{
	return active;
}

void State::pushState(States::ID state)
{
	stack.pushState(state);
}

void State::popState()
{
	stack.popState();
}

void State::clearStates()
{
	stack.clearStates();
}

void State::setActive(bool value)
{
	active = value;
}

void State::setString(std::string string)
{
	State::gameover = string;
}

sf::RenderWindow &State::getWindow()
{
	return window;
}

std::string State::getString()
{
	return State::gameover;
}
