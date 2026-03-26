#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

// Function to display board
void displayBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

// Function to check win
bool checkWin(char p) {
    // Rows & Columns
    for(int i=0; i<3; i++) {
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p)
            return true;
        if(board[0][i]==p && board[1][i]==p && board[2][i]==p)
            return true;
    }
    // Diagonals
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p)
        return true;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p)
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Function to reset board
void resetBoard() {
    char ch = '1';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ch++;
        }
    }
}

int main() {
    char player = 'X';
    int choice;
    char again;

    do {
        resetBoard();
        player = 'X';

        while(true) {
            displayBoard();
            cout << "Player " << player << ", enter position (1-9): ";
            cin >> choice;

            int row = (choice-1)/3;
            int col = (choice-1)%3;

            // Check valid move
            if(board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            // Update board
            board[row][col] = player;

            // Check win
            if(checkWin(player)) {
                displayBoard();
                cout << "Player " << player << " wins! 🎉\n";
                break;
            }

            // Check draw
            if(checkDraw()) {
                displayBoard();
                cout << "Game is a draw!\n";
                break;
            }

            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> again;

    } while(again == 'y' || again == 'Y');

    return 0;
}
