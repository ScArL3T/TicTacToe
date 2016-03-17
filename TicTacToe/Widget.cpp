#include "Widget.h"


Widget::Widget(sf::RenderWindow &window)
	: window(window)
	, selected(false)
	, active(false)
{
}

void Widget::select()
{
	selected = true;
}

void Widget::deselect()
{
	selected = false;
}

void Widget::activate()
{
	active = true;
}

void Widget::deactivate()
{
	active = false;
}

bool Widget::isSelected() const
{
	return selected;
}

bool Widget::isActive() const
{
	return active;
}