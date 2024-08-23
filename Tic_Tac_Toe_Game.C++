#include <bits/stdc++.h>  
using namespace std;

void displayBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
            if (i != 8) cout << "---|---|---\n";
        } else {
            cout << "|";
        }
    }
    cout << "\n";
}

bool checkWin(const vector<char>& board, char player) {
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (const auto& condition : winConditions) {
        if (board[condition[0]] == player && board[condition[1]] == player && board[condition[2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const vector<char>& board) {
    return all_of(board.begin(), board.end(), [](char c) { return c == 'X' || c == 'O'; });
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    vector<char> board(9, ' ');  // 3x3 grid initialized with spaces
    char currentPlayer = 'X';
    bool gameWon = false, gameDraw = false;
    int move;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1 is 'X' and Player 2 is 'O'.\n";

    do {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        
        // Convert move to board index (0-8)
        move -= 1;

        if (move < 0 || move >= 9 || board[move] != ' ') {
            cout << "Invalid move! Please try again.\n";
            continue;
        }

        board[move] = currentPlayer;

        gameWon = checkWin(board, currentPlayer);
        gameDraw = checkDraw(board);

        if (!gameWon && !gameDraw) {
            switchPlayer(currentPlayer);
        }

    } while (!gameWon && !gameDraw);

    displayBoard(board);

    if (gameWon) {
        cout << "Congratulations! Player " << currentPlayer << " wins!\n";
    } else if (gameDraw) {
        cout << "It's a draw!\n";
    }

    return 0;
}
