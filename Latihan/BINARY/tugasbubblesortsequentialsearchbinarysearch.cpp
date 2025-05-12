#include <iostream>
using namespace std;

int main() {
    // Array angka
    int angka[10] = {2, 1, 5, 9, 7, 6, 8, 3, 10, 4};
    int n = 10; // Panjang array

    // Menampilkan array angka
    cout << "Array angka: ";
    for (int i = 0; i < n; i++) {
        cout << angka[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "\n";

    // Bubble sort
    bool tukar = true;
    while (tukar) {
        tukar = false;
        for (int i = 0; i < n - 1; i++) {
            if (angka[i] > angka[i + 1]) {
                int temp = angka[i];
                angka[i] = angka[i + 1];
                angka[i + 1] = temp;
                tukar = true;

                // Menampilkan proses pengurutan
                cout << "Angka yang ditukar: " << angka[i] << " dan " << angka[i + 1] << endl;
                for (int j = 0; j < n; j++) {
                    cout << angka[j] << " ";
                }
                cout << "\n";
            }
        }
    }
    cout << "=========================================================\n\n";

    // Sequential search
    int cari;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (angka[i] == cari) {
            cout << "Angka " << cari << " ditemukan di index " << i << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Angka tidak ditemukan.\n";
    }
    cout << "=========================================================\n\n";

    // Binary search
    int cari2;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari2;

    int kiri = 0, kanan = n - 1;
    bool ketemu = false;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (angka[tengah] == cari2) {
            cout << "Angka " << cari2 << " ditemukan di index " << tengah << endl;
            ketemu = true;
            break;
        } else if (angka[tengah] > cari2) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (!ketemu) {
        cout << "Angka tidak ditemukan.\n";
    }
    cout << "=========================================================\n\n";

    return 0;
}

