#ifndef AI_H
#define AI_H

#include "Board.h"

class AI
{
public:
	explicit AI(Board &board);
	~AI();

	sf::Vector2i move();

private:
	sf::Vector3i minimax(Tile::PlayerList currentPlayer, int alpha, int beta);
	int evaluate(std::string gameover, Tile::PlayerList currentPlayer);

	Board &board;
};

#endif