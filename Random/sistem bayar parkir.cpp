#include <iostream>
using namespace std;

int main() {
    int jamMasuk, jamKeluar;
    int biayaPerJam = 3000;

    cout << "Masukkan jam masuk (0-23): ";
    cin >> jamMasuk;
    cout << "Masukkan jam keluar (0-23): ";
    cin >> jamKeluar;

    if (jamKeluar < jamMasuk) {
        jamKeluar += 24; // Jika parkir melewati tengah malam
    }

    int lamaParkir = jamKeluar - jamMasuk;
    int totalBiaya = lamaParkir * biayaPerJam;

    cout << "Lama parkir: " << lamaParkir << " jam" << endl;
    cout << "Total biaya: Rp " << totalBiaya << endl;

    return 0;
}

