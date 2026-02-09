#include "Game.h"

Game::Game()
	: board{}
	, playerA{}
	, playerB{}
	, state{}
{
}

void Game::Start()
{
	setupGame();

	state.setCurrentPlayer(playerA);

	std::vector<int> newMove(2);
	while (!state.getIsGameOver())
	{
		board.drawBoard(state);
		askForInput(newMove);
		board.makeMove(newMove, state.getCurrentPlayer());
		changeTurn();
		checkWinner();

		if (state.getWinner().getName() != " ")
		{
			bool playAnother = board.endGame(state);
			if (playAnother)
			{
				board.resetBoard();
				state.getWinner().setName(" ");
				state.setIsGameOver(false);
			}
		}
	}
}

void Game::setupGame()
{
	std::string playerName;
	char symbol = ' ';

	std::cout << "Starting new TikTakToe game." << std::endl;
	std::cout << "Enter name for player A:" << std::endl;
	std::cin >> playerName;
	playerA.setName(playerName);

	std::cout << "Enter name for player B:" << std::endl;
	std::cin >> playerName;
	playerB.setName(playerName);

	while (true)
	{
		std::cout << "What symbol does " << playerA.getName() << " want to use? (X/O): ";
		std::cin >> symbol;

		symbol = toupper(symbol);
		if (symbol == 'X' || symbol == 'O') {
			break;
		}

		std::cout << "Invalid input. Please enter 'X' or 'O'." << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	playerA.setSymbol(symbol);
	playerB.setSymbol(symbol == 'X' ? 'O' : 'X');

	std::cout << "Game started with playerA " << playerA.getName() << " with symbol " << playerA.getSymbol()
		<< " and playerB " << playerB.getName() << " with symbol " << playerB.getSymbol() << std::endl;
}

void Game::askForInput(std::vector<int> &cell)
{
	bool validInput = false;

	while (!validInput) {
		std::cout << "It's " << state.getCurrentPlayer().getName()
			<< "'s turn. Enter row and column (0-2) separated by space: ";

		if (std::cin >> cell[0] >> cell[1]) {
			if (board.isPositionValid(cell)) {
				validInput = true;
			}
			else {
				std::cout << "Invalid move! Position out of bounds or already taken." << std::endl;
			}
		}
		else {
			std::cout << "Invalid input! Please enter NUMBERS only." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

void Game::changeTurn()
{
	if (state.getCurrentPlayer().getName() == playerA.getName())
	{
		state.setCurrentPlayer(playerB);
	}
	else
	{
		state.setCurrentPlayer(playerA);
	}
}

void Game::checkWinner()
{
	char symbols[2] = {playerA.getSymbol(), playerB.getSymbol()};
	std::vector<std::vector<char>> grid = board.getGrid();
	bool spacesAvailable = false;

	for (char s: symbols)
	{
		for (int i = 0; i < grid.size(); i++)
		{
			if (grid[0][i] == s && grid[1][i] == s && grid[2][i] == s)
			{
				setWinner(s);
				break;
			}
			if (grid[i][0] == s && grid[i][1] == s && grid[i][2] == s)
			{
				setWinner(s);
				break;
			}
		}

		if (grid[0][0] == s && grid[1][1] == s && grid[2][2] == s)
		{
			setWinner(s);
			break;
		}
		if (grid[0][2] == s && grid[1][1] == s && grid[2][0] == s)
		{
			setWinner(s);
			break;
		}
	}

	for (int i = 0; i < grid.size(); i++) 
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == ' ')
			{
				spacesAvailable = true;
				break;
			}
		}
		if (spacesAvailable) break;
	}

	if (!spacesAvailable) 
	{
		setWinner('Draw');
	}

}

void Game::setWinner(char winnerSymbol)
{
	if (winnerSymbol == playerA.getSymbol())
	{
		state.setWinner(playerA);
	}
	else if (winnerSymbol == playerB.getSymbol())
	{
		state.setWinner(playerB);
	}
	else
	{
		Player draw = {};
		draw.setName("Draw");
		state.setWinner(draw);
	}
}