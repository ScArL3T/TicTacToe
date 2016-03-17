#include "Board.h"
#include <iostream>

Board::Board(sf::RenderWindow &window)
	: window(window)
{
	tiles.reserve(BOARD_SIZE*BOARD_SIZE);

	playerTexture.loadFromFile("data/x.png");
	compTexture.loadFromFile("data/circle.png");

	for (unsigned int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
	{
		int row, column;
		row = i / BOARD_SIZE; column = i % BOARD_SIZE;

		tiles.emplace_back();
		tiles.back().setMatrixPos({ row, column });

		tiles.back().setPosition({ static_cast<float>(column * 102 + 2 * column), static_cast<float>(row * 102 + 2 * row) });
	}
}

Board::~Board()
{
}

std::string Board::gameOver(Tile::PlayerList player)
{
	int patterns[] = { 0b111000000, 0b000111000, 0b000000111, // rows
		0b100100100, 0b010010010, 0b001001001, // cols
		0b100010001, 0b001010100 };

	int p1 = 0b000000000;
	int draw = 1;
	for (int i = 0; i < BOARD_SIZE; ++i)
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			if (getTile(i, j).getState() == player)
				p1 |= (1 << (i * BOARD_SIZE + j));
			else if (getTile(i, j).getState() == Tile::PlayerList::None)
				draw = 0;
		}
			
	for (int i = 0; i < 8; ++i)
		if ((p1 & patterns[i]) == patterns[i])
			return "win";

	if (draw) return "draw";

	return "nothing";
}

void Board::setFirstPlayer(Tile::PlayerList player)
{
	currentPlayer = player;
}

std::vector<sf::Vector2i> Board::generateMoves()
{
	std::vector<sf::Vector2i> moves;

	for (int i = 0; i < BOARD_SIZE; ++i)
		for (int j = 0; j < BOARD_SIZE; ++j)
			if (tiles[i*BOARD_SIZE + j].getState() == Tile::PlayerList::None)
				moves.emplace_back(tiles[i*BOARD_SIZE + j].getMatrixPos());
	
	return moves;
}

Tile::PlayerList Board::getCurrentPlayer()
{
	return currentPlayer;
}

Tile &Board::getTile(int i, int j)
{
	return tiles[i * BOARD_SIZE + j];
}

void Board::handlePlayer(const sf::Event &event)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	switch (event.type)
	{
	case sf::Event::MouseMoved:
		for (auto &tile : tiles)
		{
			if (tile.getState() == Tile::PlayerList::None)
			{
				if (tile.isInside(mousePos))
					tile.setColor(sf::Color(230, 230, 230));
				else tile.setColor(sf::Color(190, 190, 190));
			}
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (auto &tile : tiles)
			{
				if (tile.isInside(mousePos) && tile.getState() == Tile::PlayerList::None)
				{
					tile.setState(Tile::PlayerList::Player);
					tile.setTexture(playerTexture);
					currentPlayer = Tile::PlayerList::Comp;
				}
			}
		}
		break;
	default:
		break;
	}
}

void Board::handleComp(sf::Vector2i pos)
{
	tiles[pos.x * BOARD_SIZE + pos.y].setTexture(compTexture);
	tiles[pos.x * BOARD_SIZE + pos.y].setState(Tile::PlayerList::Comp);
	currentPlayer = Tile::PlayerList::Player;
}

void Board::draw()
{
	for (const auto &tile : tiles)
		window.draw(tile);
}

bool Board::isInside(int i, int j)
{
	if (i >= 0 && i<BOARD_SIZE && j >= 0 && j<BOARD_SIZE)
		return true;
	return false;
}