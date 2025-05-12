#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------" << endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Cek baris
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    // Cek kolom
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    cout << "Pemain 1, pilih tanda kamu (X atau O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    if (marker_p1 == 'X') {
        current_marker = 'X';
    } else {
        current_marker = 'O';
    }

    drawBoard();
    int player_won;

    for (int i = 0; i < 9; i++) {
        cout << "Pemain " << current_player << ", masukkan nomor slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Slot tidak valid! Coba lagi.\n";
            i--; // Mengulangi giliran jika slot tidak valid
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot sudah diisi! Coba slot lain.\n";
            i--; // Mengulangi giliran jika slot sudah terisi
            continue;
        }

        drawBoard();

        player_won = checkWin();

        if (player_won == 1) {
            cout << "Pemain 1 menang! Selamat!" << endl;
            break;
        }
        if (player_won == 2) {
            cout << "Pemain 2 menang! Selamat!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "Permainan berakhir seri!" << endl;
    }
}

int main() {
    game();
    return 0;
}

