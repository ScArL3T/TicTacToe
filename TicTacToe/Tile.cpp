#include "Tile.h"

Tile::Tile()
	: size(100, 100)
	, pos(0, 0)
	, state(PlayerList::None)
{
	shape.setSize(size);
}

Tile::~Tile()
{
}

void Tile::setMatrixPos(sf::Vector2i pos)
{
	this->pos = pos;
}

void Tile::setState(Tile::PlayerList state)
{
	this->state = state;
}

void Tile::setColor(sf::Color color)
{
	shape.setFillColor(color);
}

void Tile::setTexture(sf::Texture &texture)
{
	this->texture = texture;
	shape.setTexture(&this->texture);
}

bool Tile::isInside(sf::Vector2i mouse)
{
	sf::FloatRect bounds(getPosition().x, getPosition().y, size.x, size.y);
	return bounds.contains(static_cast<sf::Vector2f>(mouse));
}

const sf::Vector2i Tile::getMatrixPos()
{
	return pos;
}

const Tile::PlayerList Tile::getState()
{
	return state;
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(shape, states);
}
