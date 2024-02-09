#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const std::vector<std::vector<char>> &board);
bool isMoveValid(const std::vector<std::vector<char>> &board, int row, int col);
bool checkForWin(const std::vector<std::vector<char>> &board, char player);
bool checkForDraw(const std::vector<std::vector<char>> &board);
void switchPlayers(char &currentPlayer);

int main()
{
    vector<vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameIsRunning = true;

    while (gameIsRunning)
    {

        displayBoard(board);

        int row, col;
        do
        {
            cout << "Player " << currentPlayer << ", enter your move (row and column, separated by space): ";
            cin >> row >> col;
        } while (!isMoveValid(board, row, col));

        board[row - 1][col - 1] = currentPlayer;

        if (checkForWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameIsRunning = false;
        }
        else if (checkForDraw(board))
        {

            displayBoard(board);
            cout << "It's a draw!\n";
            gameIsRunning = false;
        }
        else
        {

            switchPlayers(currentPlayer);
        }
    }

    return 0;
}

void displayBoard(const std::vector<std::vector<char>> &board)
{
    cout << "\nCurrent Board:\n";
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isMoveValid(const std::vector<std::vector<char>> &board, int row, int col)
{
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
    {
        cout << "Invalid move. Try again.\n";
        return false;
    }
    return true;
}

bool checkForWin(const std::vector<std::vector<char>> &board, char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkForDraw(const std::vector<std::vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayers(char &currentPlayer)
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
