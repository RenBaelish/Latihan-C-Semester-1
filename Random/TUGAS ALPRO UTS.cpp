#include <iostream>
#include <string>
using namespace std;

int main() {
    // Daftar pilihan utama tiket
    string pilihan_tiket[] = {"Tiket Masuk TMII", "Jagat Satwa Nusantara", "Teater Keong Mas"};
    
    // Daftar tiket TMII
    string tiket_tmii[] = {
        "Tiket Masuk Orang (Rp. 25.000)",
        "Bundling TMII & Kereta Gantung Weekdays (Rp. 60.000)",
        "Tiket Masuk Mobil (Rp. 35.000)",
        "Tiket Masuk Sepeda (Rp. 10.000)",
        "Tiket Masuk Bus/Truk (Rp. 60.000)",
        "Single Entry (Orang + Sepeda) (Rp. 35.000)",
        "Kereta Gantung Bertiga - Weekdays (Rp. 135.000)",
        "Kereta Gantung Beli 3 Gratis 1 - Weekdays (Rp. 150.000)",
        "Kereta Gantung - Weekday (Rp. 50.000)"
    };
    
    // Daftar tiket Jagat Satwa Nusantara
    string tiket_jagat[] = {
        "Bundling Taman Burung - Weekdays (Rp. 77.500)",
        "Bundling Dunia Air Tawar - Weekdays (Rp. 62.500)",
        "Bundling Museum Komodo - Weekdays (Rp. 62.500)",
        "Bundling 3 Wahana (Rp. 147.500)",
        "Bundling Museum Komodo & Taman Burung (Rp. 102.500)",
        "Bundling Dunia Air Tawar & Taman Burung (Rp. 102.500)",
        "Bundling Dunia Air Tawar & Museum Komodo (Rp. 92.500)"
    };
    
    // Daftar tiket Teater Keong Mas
    string tiket_keong[] = {
        "Bundling TMII & Keong Mas (Rp. 56.000)"
    };
    
    // Harga tiket TMII
    int harga_tmii[] = {25000, 60000, 35000, 10000, 60000, 35000, 135000, 150000, 50000};
    
    // Harga tiket Jagat Satwa Nusantara
    int harga_jagat[] = {77500, 62500, 62500, 147500, 102500, 102500, 92500};
    
    // Harga tiket Teater Keong Mas
    int harga_keong[] = {56000};
    
    int pilihan, pilihan_detail, jumlah_tiket, total_harga = 0;
    string email, nama, nomor_telepon, jenis_kelamin, tanggal;

    // Menampilkan pilihan utama
    cout << "Pilih Tiket yang Ingin Dipesan:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << pilihan_tiket[i] << endl;
    }

    // Pilihan tiket utama
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;

    // Memasukkan pilihan tanggal
    cout << "\nMasukkan tanggal (format DD-MM-YYYY): ";
    cin >> tanggal;

    // Jika memilih Tiket Masuk TMII
    if (pilihan == 1) {
        cout << "\nPilih Tiket TMII:" << endl;
        for (int i = 0; i < 9; i++) {
            cout << i + 1 << ". " << tiket_tmii[i] << endl;
        }

        cout << "Masukkan pilihan tiket TMII: ";
        cin >> pilihan_detail;

        // Validasi pilihan TMII
        if (pilihan_detail < 1 || pilihan_detail > 9) {
            cout << "Pilihan tidak valid!" << endl;
            return 0;
        }

        // Masukkan jumlah tiket
        cout << "Masukkan jumlah tiket: ";
        cin >> jumlah_tiket;

        // Menghitung total harga tiket TMII
        for (int i = 0; i < jumlah_tiket; i++) {
            total_harga += harga_tmii[pilihan_detail - 1];
        }
    }

    // Jika memilih Tiket Masuk Jagat Satwa Nusantara
    else if (pilihan == 2) {
        cout << "\nPilih Tiket Jagat Satwa Nusantara:" << endl;
        for (int i = 0; i < 7; i++) {
            cout << i + 1 << ". " << tiket_jagat[i] << endl;
        }

        cout << "Masukkan pilihan tiket Jagat Satwa Nusantara: ";
        cin >> pilihan_detail;

        // Validasi pilihan Jagat Satwa Nusantara
        if (pilihan_detail < 1 || pilihan_detail > 7) {
            cout << "Pilihan tidak valid!" << endl;
            return 0;
        }

        // Masukkan jumlah tiket
        cout << "Masukkan jumlah tiket: ";
        cin >> jumlah_tiket;

        // Menghitung total harga tiket Jagat Satwa Nusantara
        for (int i = 0; i < jumlah_tiket; i++) {
            total_harga += harga_jagat[pilihan_detail - 1];
        }
    }

    // Jika memilih Tiket Masuk Teater Keong Mas
    else if (pilihan == 3) {
        cout << "\nPilih Tiket Teater Keong Mas:" << endl;
        for (int i = 0; i < 1; i++) {
            cout << i + 1 << ". " << tiket_keong[i] << endl;
        }

        cout << "Masukkan pilihan tiket Teater Keong Mas: ";
        cin >> pilihan_detail;

        // Validasi pilihan Teater Keong Mas
        if (pilihan_detail != 1) {
            cout << "Pilihan tidak valid!" << endl;
            return 0;
        }

        // Masukkan jumlah tiket
        cout << "Masukkan jumlah tiket: ";
        cin >> jumlah_tiket;

        // Menghitung total harga tiket Teater Keong Mas
        for (int i = 0; i < jumlah_tiket; i++) {
            total_harga += harga_keong[pilihan_detail - 1];
        }
    }

    // Memasukkan data pengguna
    cout << "\nMasukkan email: ";
    cin >> email;
    cout << "Masukkan nomor telepon: ";
    cin >> nomor_telepon;
    cout << "Masukkan nama lengkap: ";
    cin.ignore();  // Untuk mengabaikan newline character
    getline(cin, nama);
    cout << "Pilih jenis kelamin (L/P): ";
    cin >> jenis_kelamin;

    // Menampilkan ringkasan tiket
    cout << "\n--- Ringkasan Tiket ---" << endl;
    cout << "Nama: " << nama << endl;
    cout << "Email: " << email << endl;
    cout << "Nomor Telepon: " << nomor_telepon << endl;
    cout << "Jenis Kelamin: " << jenis_kelamin << endl;
    cout << "Tanggal: " << tanggal << endl;
    cout << "Total Harga: Rp. " << total_harga << endl;

    cout << "\nTerima kasih, pesanan Anda telah berhasil!" << endl;

    return 0;
}

