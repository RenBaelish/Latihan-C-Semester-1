#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk fitur login admin
bool loginAdmin() {
    string username, password;
    const string ADMIN_USERNAME = "admin";
    const string ADMIN_PASSWORD = "admin123";

    cout << "\n=== Fitur Login Admin ===" << endl;

    // Proses login
    while (true) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        // Periksa kecocokan username dan password
        if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
            cout << "Login berhasil! Selamat datang di menu admin.\n";
            return true;
        } else {
            cout << "Login gagal. Username atau password salah. Coba lagi.\n";
        }
    }
}

// Menu utama admin
void menuAdmin() {
    int pilihan;

    while (true) {
        cout << "\n=== Menu Utama Admin ===" << endl;
        cout << "1. Lihat Semua Data Booking" << endl;
        cout << "2. Lihat Semua Data Pengguna" << endl;
        cout << "3. Perbarui Laporan Pengguna" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Menampilkan semua data booking...\n";
                break;
            case 2:
                cout << "Menampilkan semua data pengguna...\n";
                break;
            case 3:
                cout << "Memperbarui laporan pengguna...\n";
                break;
            case 4:
                cout << "Keluar dari menu admin. Terima kasih.\n";
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}

int main() {
    // Login admin
    if (loginAdmin()) {
        // Jika login berhasil, arahkan ke menu utama admin
        menuAdmin();
    }

    return 0;
}

