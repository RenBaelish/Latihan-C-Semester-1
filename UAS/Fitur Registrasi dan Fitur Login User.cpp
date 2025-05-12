#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk menyimpan data pengguna
struct Pengguna {
    string nama;
    string email;
    string alamat;
    string username;
    string password;
};

// Deklarasi vector untuk menyimpan data pengguna
vector<Pengguna> data_pengguna;

// Fungsi untuk mendaftarkan pengguna baru
void pendaftaranPengguna() {
    Pengguna penggunaBaru;
    bool sudahTerdaftar = false;

    cout << "\n=== Pendaftaran Pengguna ===" << endl;
    do {
        // Input data pengguna
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, penggunaBaru.nama);

        cout << "Masukkan Email: ";
        cin >> penggunaBaru.email;

        cout << "Masukkan Alamat: ";
        cin.ignore();
        getline(cin, penggunaBaru.alamat);

        cout << "Masukkan Username: ";
        cin >> penggunaBaru.username;

        cout << "Masukkan Password: ";
        cin >> penggunaBaru.password;

        // Periksa kecocokan dengan data yang ada
        sudahTerdaftar = false;
        for (const auto& pengguna : data_pengguna) {
            if (pengguna.username == penggunaBaru.username || pengguna.email == penggunaBaru.email) {
                sudahTerdaftar = true;
                cout << "Username atau email sudah terdaftar. Silakan coba lagi.\n" << endl;
                break;
            }
        }

    } while (sudahTerdaftar);

    // Tambahkan pengguna baru ke vector data pengguna
    data_pengguna.push_back(penggunaBaru);
    cout << "Akun berhasil dibuat! Silakan login.\n" << endl;
}

// Fungsi untuk login pengguna
void loginPengguna() {
    string username, password;
    bool loginBerhasil = false;

    cout << "\n=== Login Pengguna ===" << endl;
    do {
        // Input username dan password
        cout << "Masukkan Username: ";
        cin >> username;

        cout << "Masukkan Password: ";
        cin >> password;

        // Periksa kecocokan dengan data pengguna
        for (const auto& pengguna : data_pengguna) {
            if (pengguna.username == username && pengguna.password == password) {
                loginBerhasil = true;
                cout << "Login berhasil! Selamat datang, " << pengguna.nama << ".\n" << endl;
                break;
            }
        }

        if (!loginBerhasil) {
            cout << "Username atau password salah. Silakan coba lagi.\n" << endl;
        }

    } while (!loginBerhasil);
}

// Fungsi utama untuk menggabungkan pendaftaran dan login
int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Pendaftaran dan Login ===" << endl;
        cout << "1. Pendaftaran Pengguna Baru" << endl;
        cout << "2. Login Pengguna" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pendaftaranPengguna();
                break;
            case 2:
                if (data_pengguna.empty()) {
                    cout << "Tidak ada pengguna terdaftar. Silakan daftar terlebih dahulu.\n" << endl;
                } else {
                    loginPengguna();
                }
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem ini.\n" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
        }

    } while (pilihan != 3);

    return 0;
}

