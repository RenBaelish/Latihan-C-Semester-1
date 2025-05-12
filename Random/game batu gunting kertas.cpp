#include <iostream>
#include <cstdlib> // untuk rand() dan srand()
#include <ctime>   // untuk time()
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3; // 0 untuk Batu, 1 untuk Kertas, 2 untuk Gunting

    switch (choice) {
        case 0: return "Batu";
        case 1: return "Kertas";
        case 2: return "Gunting";
    }
    return "";
}

string getPlayerChoice() {
    int choice;
    cout << "Pilih:\n1. Batu\n2. Kertas\n3. Gunting\nMasukkan pilihan Anda (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: return "Batu";
        case 2: return "Kertas";
        case 3: return "Gunting";
        default: return "Invalid";
    }
}

void determineWinner(string playerChoice, string computerChoice) {
    cout << "Anda memilih: " << playerChoice << endl;
    cout << "Komputer memilih: " << computerChoice << endl;

    if (playerChoice == computerChoice) {
        cout << "Hasil: Seri!" << endl;
    } else if ((playerChoice == "Batu" && computerChoice == "Gunting") ||
               (playerChoice == "Gunting" && computerChoice == "Kertas") ||
               (playerChoice == "Kertas" && computerChoice == "Batu")) {
        cout << "Hasil: Anda Menang!" << endl;
    } else {
        cout << "Hasil: Komputer Menang!" << endl;
    }
}

int main() {
    srand(time(0)); // Seed untuk angka acak
    char playAgain;

    cout << "Selamat datang di permainan Batu, Kertas, Gunting!" << endl;

    do {
        string playerChoice = getPlayerChoice();
        if (playerChoice == "Invalid") {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
            continue;
        }

        string computerChoice = getComputerChoice();
        determineWinner(playerChoice, computerChoice);

        cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Terima kasih telah bermain!" << endl;
    return 0;
}

