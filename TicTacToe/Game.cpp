#include "Game.h"

Game::Game(StateManager &stack, sf::RenderWindow &window)
	: State(stack, window)
	, board(window)
	, ai(board)
{
	board.setFirstPlayer(Tile::PlayerList::Player);
}


Game::~Game()
{
}

void Game::handleEvent(const sf::Event &event)
{
	if(board.getCurrentPlayer() == Tile::PlayerList::Player)
		board.handlePlayer(event);

	// Check if gameover
	if (board.gameOver(Tile::PlayerList::Player) != "nothing")
	{
		if(board.gameOver(Tile::PlayerList::Player) == "win")
			setString("YOU WIN!");
		else setString("DRAW!");
		popState();
		pushState(States::ID::GameOver);
	}
}

void Game::update(sf::Time dt)
{
	if (board.getCurrentPlayer() == Tile::PlayerList::Comp)
		board.handleComp(ai.move());

	// Check if gameover
	if (board.gameOver(Tile::PlayerList::Comp) != "nothing")
	{
		if (board.gameOver(Tile::PlayerList::Comp) == "win")
			setString("YOU LOSE!");
		else setString("DRAW!");
		popState();
		pushState(States::ID::GameOver);
	}
}

void Game::draw()
{
	board.draw();
}