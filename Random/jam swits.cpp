#include <iostream>
using namespace std;

int main() {
    double saldo, jumlah;
    const double saldo_minimum = 100000;
    const double biaya_admin = 50000;
    const double batas_penarikan = 5000000;

    // Input saldo awal
    cout << "Masukkan saldo awal: Rp";
    cin >> saldo;

    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Setor Uang\n";
        cout << "3. Tarik Uang\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Cek Saldo
                cout << "Saldo saat ini: Rp" << saldo << endl;
                break;
            case 2:
                // Setor Uang
                cout << "Masukkan jumlah yang akan disetor: Rp";
                cin >> jumlah;
                saldo += jumlah;
                cout << "Setoran berhasil! Saldo Anda: Rp" << saldo << endl;
                break;
            case 3:
                // Tarik Uang
                cout << "Masukkan jumlah yang akan ditarik: Rp";
                cin >> jumlah;

                if (jumlah > batas_penarikan) {
                    cout << "Gagal: Batas maksimum penarikan harian adalah Rp" << batas_penarikan << endl;
                } else if (saldo - jumlah < saldo_minimum) {
                    cout << "Gagal: Saldo tidak mencukupi setelah penarikan." << endl;
                } else {
                    saldo -= jumlah;
                    cout << "Penarikan berhasil! Saldo Anda: Rp" << saldo << endl;

                    if (saldo < 500000) {
                        saldo -= biaya_admin;
                        cout << "Saldo kurang dari Rp500.000, biaya admin Rp" << biaya_admin << " dikenakan." << endl;
                    }
                }
                break;
            case 4:
                // Keluar
                cout << "Terima kasih sudah menggunakan layanan kami.\n";
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}

