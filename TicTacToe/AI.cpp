#include "AI.h"

AI::AI(Board &board)
	: board(board)
{
}

AI::~AI()
{
}

sf::Vector2i AI::move()
{
	sf::Vector3i pos = minimax(Tile::PlayerList::Comp, -300, 300); 
	return{ pos.x, pos.y };
}

sf::Vector3i AI::minimax(Tile::PlayerList currentPlayer, int alpha, int beta)
{
	int row = -1;
	int col = -1;
	int score = 0;

	std::string gameover = board.gameOver(currentPlayer);

	if (gameover != "nothing")
	{
		score = evaluate(gameover, currentPlayer);
		return{ row, col, score };
	}
	else
	{
		std::vector<sf::Vector2i> moves = board.generateMoves();
		for (auto &move : moves)
		{
			board.getTile(move.x, move.y).setState(currentPlayer);

			if (currentPlayer == Tile::PlayerList::Comp)
			{
				score = minimax(Tile::PlayerList::Player, alpha, beta).z;
				if (score > alpha)
				{
					alpha = score;
					row = move.x;
					col = move.y;
				}
			}
			else
			{
				score = minimax(Tile::PlayerList::Comp, alpha, beta).z;
				if (score < beta)
				{
					beta = score;
					row = move.x;
					col = move.y;
				}
			}
			board.getTile(move.x, move.y).setState(Tile::PlayerList::None);

			if (alpha >= beta) break;
		}
		return{ row, col, (currentPlayer == Tile::PlayerList::Comp) ? alpha : beta };
	}
}

int AI::evaluate(std::string gameover, Tile::PlayerList currentPlayer)
{
	if (gameover == "win")
		if (currentPlayer == Tile::PlayerList::Comp)
			return 10;
		else return -10;
	else return 0;
}