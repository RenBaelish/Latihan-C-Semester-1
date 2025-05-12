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

// Struktur untuk menyimpan data layanan
struct Layanan {
    string nama;
    int harga;
};

// Struktur untuk menyimpan data booking
struct Booking {
    string layanan;
    string waktu;
};

// Data simulasi
vector<string> data_booking = {"Booking 1: User A", "Booking 2: User B"};
vector<string> data_pembayaran = {"Proses Bayar: User A - Lunas", "Proses Bayar: User B - Belum Lunas"};
vector<Pengguna> data_pengguna = {
    {"User A", "usera@example.com", "Jl. Mawar No. 10", "usera", "passa"},
    {"User B", "userb@example.com", "Jl. Melati No. 25", "userb", "passb"}
};
vector<string> laporan_transaksi = {"User A: Transaksi Sukses", "User B: Menunggu Pembayaran"};

// Deklarasi vector untuk menyimpan data pengguna dan layanan
vector<Layanan> daftarLayanan = {
    {"Potong Rambut", 50000},
    {"Styling", 75000},
    {"Cuci Rambut", 30000}
};

vector<Booking> dataBooking;

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

// Fungsi untuk menampilkan layanan yang tersedia
void tampilkanLayanan() {
    cout << "\n=== Layanan yang Tersedia ===" << endl;
    for (size_t i = 0; i < daftarLayanan.size(); i++) {
        cout << i + 1 << ". " << daftarLayanan[i].nama 
             << " - Rp " << daftarLayanan[i].harga << endl;
    }
}

// Fungsi untuk memverifikasi ketersediaan waktu
bool verifikasiWaktu(const string& waktu) {
    for (const auto& booking : dataBooking) {
        if (booking.waktu == waktu) {
            return false; // Waktu sudah terbooking
        }
    }
    return true; // Waktu tersedia
}

// Fungsi untuk fitur booking
void fiturBooking() {
    int pilihanLayanan;
    string waktu;
    Booking bookingBaru;

    cout << "\n=== Fitur Booking ===" << endl;

    // Tampilkan daftar layanan
    tampilkanLayanan();

    // Pilih layanan
    cout << "Pilih layanan (1-" << daftarLayanan.size() << "): ";
    cin >> pilihanLayanan;

    if (pilihanLayanan < 1 || pilihanLayanan > daftarLayanan.size()) {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    bookingBaru.layanan = daftarLayanan[pilihanLayanan - 1].nama;

    // Input waktu
    do {
        cout << "Masukkan waktu booking yang diinginkan (format: HH:MM): ";
        cin >> waktu;

        if (!verifikasiWaktu(waktu)) {
            cout << "Waktu tidak tersedia. Silakan pilih waktu lain.\n";
        } else {
            bookingBaru.waktu = waktu;
            break;
        }
    } while (true);

    // Konfirmasi booking
    cout << "\n=== Konfirmasi Booking ===" << endl;
    cout << "Layanan: " << bookingBaru.layanan << endl;
    cout << "Waktu: " << bookingBaru.waktu << endl;

    char konfirmasi;
    cout << "Konfirmasi booking? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        // Simpan booking
        dataBooking.push_back(bookingBaru);
        cout << "Booking berhasil! Silakan lakukan pembayaran.\n";
    } else {
        cout << "Booking dibatalkan.\n";
    }
}

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

// Fungsi menu utama admin
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
    int pilihan;
    do {
        cout << "\n=== Sistem Pendaftaran, Login, Booking, dan Admin ===" << endl;
        cout << "1. Pendaftaran Pengguna Baru" << endl;
        cout << "2. Login Pengguna" << endl;
        cout << "3. Fitur Booking" << endl;
        cout << "4. Login Admin" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pendaftaranPengguna();
                break;
            case 2:
                loginPengguna();
                break;
            case 3:
                fiturBooking();
                break;
            case 4:
                if (loginAdmin()) {
                    menuAdmin();
                }
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}

