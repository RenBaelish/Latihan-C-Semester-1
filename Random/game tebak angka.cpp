#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Untuk menghasilkan angka acak setiap kali program dijalankan
    int angka_acak = rand() % 100 + 1; // Angka acak antara 1 dan 100
    int tebakan;
    int percobaan = 0;

    cout << "Selamat datang di permainan tebak angka!" << endl;

    do {
        cout << "Masukkan tebakanmu (1 - 100): ";
        cin >> tebakan;
        percobaan++;

        if (tebakan > angka_acak)
            cout << "Terlalu tinggi!" << endl;
        else if (tebakan < angka_acak)
            cout << "Terlalu rendah!" << endl;
        else
            cout << "Selamat! Kamu menebak angka dalam " << percobaan << " percobaan." << endl;

    } while (tebakan != angka_acak);

    return 0;
}

