#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 3

#include "Tile.h"

class Board : private sf::NonCopyable
{
public:
	explicit Board(sf::RenderWindow &window);
	~Board();

	std::string gameOver(Tile::PlayerList player);

	void setFirstPlayer(Tile::PlayerList player);

	std::vector<sf::Vector2i> generateMoves();
	
	Tile::PlayerList getCurrentPlayer();
	Tile &getTile(int i, int j);

	void handlePlayer(const sf::Event &event);
	void handleComp(sf::Vector2i pos);
	void draw();

private:
	bool isInside(int i, int j);

	std::vector<Tile> tiles;
	Tile lastTile;

	Tile::PlayerList currentPlayer;

	sf::RenderWindow  &window;
	sf::Texture playerTexture;
	sf::Texture compTexture;
};

#endif