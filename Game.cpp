#include "Game.h"

Game::Game()
	: board{}
	, playerA{}
	, playerB{}
	, state{}
{
	std::cout << "Game initialized." << std::endl;
}

void Game::Start()
{
	setupGame();

	state.setCurrentPlayer(playerA);

	std::vector<int> newMove(2);
	while (!state.getIsGameOver())
	{
		board.drawBoard(state);
		
		// Ask for player A/B input
		askForInput(newMove);

		// Update board with player A/B input taking into account currentPlayer
		board.makeMove(newMove, state.getCurrentPlayer());

		checkWinner();

		changeTurn();
		


		// Check if game is over

			// If game is over, declare winner and ask if they want to play again

		// If game is not over, switch currentPlayer and keep playing
	}

	std::cout << "PARTIDA FINIQUITADA CRACK.";

}

void Game::setupGame()
{
	std::string playerName;
	char symbol;

	std::cout << "Starting new TikTakToe game." << std::endl;
	std::cout << "Enter name for player A:" << std::endl;
	std::cin >> playerName;
	playerA.setName(playerName);

	std::cout << "Enter name for player B:" << std::endl;
	std::cin >> playerName;
	playerB.setName(playerName);

	std::cout << "What symbol does " << playerA.getName() << " want to use? (X/O)" << std::endl;
	std::cin >> symbol;
	playerA.setSymbol(symbol);
	playerB.setSymbol(symbol == 'X' ? 'O' : 'X');

	std::cout << "Game started with playerA " << playerA.getName() << " with symbol " << playerA.getSymbol()
		<< " and playerB " << playerB.getName() << " with symbol " << playerB.getSymbol() << std::endl;
}

void Game::askForInput(std::vector<int> &cell)
{

	//std::cout << "Please enter your move (row):" << std::endl;
	//// Pregunta: Esta sintaxis es para encapsular el acceso al valor primero y luego a la posición. En caso de no hacerlo así que estaríamos haciendo??
	//// std::cin >> (*pCell)[0];
	//// Diferencia con hacerlo mediante referencia?
	//std::cin >> cell[0];
	//std::cout << "Please enter your move (column):" << std::endl;
	//std::cin >> cell[1];

	//// Check if input is valid
	//if (!board.isPositionValid(cell))
	//{
	//	std::cout << "Invalid input. Please select a valid move: (row):" << std::endl;
	//	std::cin >> cell[0];
	//	std::cout << "Please enter your move (column):" << std::endl;
	//	std::cin >> cell[1];
	//}
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
	char symbols[3] = {playerA.getSymbol(), playerB.getSymbol()};
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