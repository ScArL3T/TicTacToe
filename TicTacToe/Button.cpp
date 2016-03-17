#include "Button.h"


Button::Button(sf::RenderWindow &window)
	: Widget(window)
{
}


Button::~Button()
{
}

bool Button::isSelectable() const 
{
	return true;
}

void Button::select() 
{

}

void Button::deselect()
{

}

void Button::activate()
{

}

void Button::deactivate()
{

}

void Button::setFunction(Function function)
{

}

void Button::setText(const std::string & text)
{

}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void Button::changeTexture(Type texture)
{

}
