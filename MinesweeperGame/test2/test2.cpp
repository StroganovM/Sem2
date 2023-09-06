#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

void generate_board(int board[MAX_SIZE][MAX_SIZE], int n, int m, int num_mines) {
    // Generate a board with n rows and m columns with num_mines mines randomly placed.
    srand(time(NULL));
    int count = 0;
    while (count < num_mines) {
        int i = rand() % n;
        int j = rand() % m;
        if (board[i][j] == -1) {
            continue;
        }
        board[i][j] = -1;
        count++;
    }
}

void print_board(int board[MAX_SIZE][MAX_SIZE], int n, int m) {
    // Print the current state of the board.
    cout << " ";
    for (int j = 0; j < m; j++) {
        cout << j << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) {
                cout << "* ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void update_board(int board[MAX_SIZE][MAX_SIZE], int n, int m, int row, int col) {
    // Update the board based on the user's input.
    if (board[row][col] == -1) {
        cout << "You lose!" << endl;
        exit(0);
    }
    int count = 0;
    for (int i = max(0, row-1); i <= min(n-1, row+1); i++) {
        for (int j = max(0, col-1); j <= min(m-1, col+1); j++) {
            if (board[i][j] == -1) {
                count++;
            }
        }
    }
    board[row][col] = count;
    if (count == 0) {
        for (int i = max(0, row-1); i <= min(n-1, row+1); i++) {
            for (int j = max(0, col-1); j <= min(m-1, col+1); j++) {
                if (board[i][j] == 0) {
                    update_board(board, n, m, i, j);
                }
            }
        }
    }
}

int main() {
    int n, m, num_mines;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    cout << "Enter the number of mines: ";
    cin >> num_mines;

    int board[MAX_SIZE][MAX_SIZE] = {0};
    generate_board(board, n, m, num_mines);

    while (true) {
        print_board(board, n, m);
        int row, col;
        cout << "Enter a row and column to check: ";
        cin >> row >> col;
        update_board(board, n, m, row, col);
    }

    return 0;
}
