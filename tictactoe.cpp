#include <iostream>
#include <string>
using namespace std;

// function to display the board
void displayBoard(char board[3][3])
{
    cout << "   1  2  3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << "[" << board[i][j] << "]";
        }
        cout << endl;
    }
}

// function to check if the game is over
bool isGameOver(char board[3][3], char player)
{
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main()
{
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1 = 'saad';
    char player2 = 'saib';
    char currentPlayer = player1;
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;
    displayBoard(board);

    // main game loop
    while (true) {
        // get input from current player
        cout << currentPlayer << "'s turn. Enter row and column (e.g. 1 2): ";
        cin >> row >> col;

        // check if input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }
        if (board[row - 1][col - 1] != ' ') {
            cout << "That position is already taken. Please try again." << endl;
            continue;
        }

        // update board and display it
        board[row - 1][col - 1] = currentPlayer;
        displayBoard(board);

        // check if game is over
        if (isGameOver(board, currentPlayer)) {
            cout <<endl<<endl<<"****"<< currentPlayer << " wins!****" << endl;
            break;
        }
        if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
            && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
            && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
            cout << "Game over. It's a tie!" << endl;
            break;
        }

        // switch to other player
    if (currentPlayer == player1) {
        currentPlayer = player2;
    }
    else {
        currentPlayer = player1;
    }
}

return 0;
}

