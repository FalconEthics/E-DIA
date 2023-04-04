#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE] = { {'1','2','3'},
                                       {'4','5','6'},
                                       {'7','8','9'} };

char player = 'X';

void drawBoard() {
    system("cls");
    cout << "\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     \n\n";
}

void playerTurn() {
    int choice;
    cout << "Player " << player << ", enter a number: ";
    cin >> choice;
    switch (choice) {
        case 1:
            if (board[0][0] == '1')
                board[0][0] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 2:
            if (board[0][1] == '2')
                board[0][1] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 3:
            if (board[0][2] == '3')
                board[0][2] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 4:
            if (board[1][0] == '4')
                board[1][0] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 5:
            if (board[1][1] == '5')
                board[1][1] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 6:
            if (board[1][2] == '6')
                board[1][2] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 7:
            if (board[2][0] == '7')
                board[2][0] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        case 8:
            if (board[2][1] == '8')
                board[2][1] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;

        case 9:
            if (board[2][2] == '9')
                board[2][2] = player;
            else {
                cout << "Invalid move!";
                playerTurn();
            }
            break;
        default:
            cout << "Invalid move!";
            playerTurn();
            break;
    }
}

bool isGameOver() {
// Check rows for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
// Check columns for a win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
// Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
// Check for a tie
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer() {
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

int main() {
    int choice;
    bool gameover = false;
    while (!gameover) {
        drawBoard();
        playerTurn();
        gameover = isGameOver();
        switchPlayer();
    }
    drawBoard();
    if (player == 'X')
        cout << "Player O wins!";
    else
        cout << "Player X wins!";
    return 0;
}