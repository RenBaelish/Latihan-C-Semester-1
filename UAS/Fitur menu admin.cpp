#include <iostream>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data pengguna
struct Pengguna {
    string nama;
    string email;
    string alamat;
};

// Data simulasi
vector<string> data_booking = {"Booking 1: User A", "Booking 2: User B"};
vector<string> data_pembayaran = {"Proses Bayar: User A - Lunas", "Proses Bayar: User B - Belum Lunas"};
vector<Pengguna> data_pengguna = {
    {"User A", "usera@example.com", "Jl. Mawar No. 10"},
    {"User B", "userb@example.com", "Jl. Melati No. 25"}
};
vector<string> laporan_transaksi = {"User A: Transaksi Sukses", "User B: Menunggu Pembayaran"};

// Fungsi untuk menampilkan data dalam vector<string>
void tampilkanData(const vector<string>& data, const string& header) {
    cout << "\n" << header << ":" << endl;
    for (const string& item : data) {
        cout << "- " << item << endl;
    }
}

// Fungsi untuk menampilkan data pengguna
void tampilkanDataPengguna(const vector<Pengguna>& data) {
    cout << "\nData Pengguna:" << endl;
    for (const Pengguna& pengguna : data) {
        cout << "Nama   : " << pengguna.nama << endl;
        cout << "Email  : " << pengguna.email << endl;
        cout << "Alamat : " << pengguna.alamat << endl;
        cout << "----------------------" << endl;
    }
}

// Fungsi menu admin
void menuAdmin() {
    int pilihan;
    do {
        cout << "\nMenu Admin:" << endl;
        cout << "1. Lihat Semua Data Booking" << endl;
        cout << "2. Lihat Proses Bayar Pengguna" << endl;
        cout << "3. Lihat Semua Data Pengguna" << endl;
        cout << "4. Lihat Laporan Transaksi Pengguna" << endl;
        cout << "5. Log Out" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data_booking, "Semua Data Booking");
                break;
            case 2:
                tampilkanData(data_pembayaran, "Proses Bayar Pengguna");
                break;
            case 3:
                tampilkanDataPengguna(data_pengguna);
                break;
            case 4:
                tampilkanData(laporan_transaksi, "Laporan Transaksi Pengguna");
                break;
            case 5:
                cout << "Log Out..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}

int main() {
    // Menjalankan menu admin
    menuAdmin();
    return 0;
}

