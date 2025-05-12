#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGuessTheNumber() {
    // Menetapkan rentang angka yang akan ditebak
    int minRange = 1;
    int maxRange = 100;
    
    // Menghasilkan angka acak antara 1 dan 100
    srand(time(0));  // Menggunakan waktu sebagai seed untuk angka acak
    int numberToGuess = rand() % (maxRange - minRange + 1) + minRange;
    
    int guess;  // Tebakan pemain
    int attempts = 10;  // Jumlah kesempatan
    bool correctGuess = false;

    cout << "Selamat datang di permainan Tebak Angka!" << endl;
    cout << "Saya telah memilih angka antara " << minRange << " dan " << maxRange << "." << endl;
    cout << "Anda memiliki " << attempts << " kesempatan untuk menebak angka tersebut." << endl;

    // Permainan dimulai
    while (attempts > 0 && !correctGuess) {
        cout << "Tebakan Anda (kesempatan tersisa " << attempts << "): ";
        cin >> guess;
        
        if (guess < minRange || guess > maxRange) {
            cout << "Tebakan harus berada antara " << minRange << " dan " << maxRange << "." << endl;
        } else if (guess < numberToGuess) {
            cout << "Tebakan Anda terlalu rendah!" << endl;
        } else if (guess > numberToGuess) {
            cout << "Tebakan Anda terlalu tinggi!" << endl;
        } else {
            correctGuess = true;
            cout << "Selamat! Anda berhasil menebak angka " << numberToGuess << " dengan benar!" << endl;
        }

        attempts--;  // Mengurangi kesempatan setiap kali pemain melakukan tebakan
    }

    if (!correctGuess) {
        cout << "Maaf, Anda kehabisan kesempatan. Angka yang benar adalah " << numberToGuess << "." << endl;
    }
}

int main() {
    char playAgain;

    // Loop untuk bermain lagi
    do {
        playGuessTheNumber();
        cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Terima kasih telah bermain!" << endl;
    return 0;
}

