#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile final : public sf::Drawable, public sf::Transformable
{
public:
	enum class PlayerList
	{
		None = 0,
		Player,
		Comp
	};

	Tile();
	~Tile();

	void setMatrixPos(sf::Vector2i pos);
	void setState(PlayerList state);
	void setColor(sf::Color color);
	void setTexture(sf::Texture &texture);

	bool isInside(sf::Vector2i mouse);

	const sf::Vector2i getMatrixPos();
	const PlayerList getState();
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	sf::Texture  texture;
	sf::Vector2f size;
	sf::RectangleShape shape;

	sf::Vector2i pos;
	PlayerList   state;
};

#endif