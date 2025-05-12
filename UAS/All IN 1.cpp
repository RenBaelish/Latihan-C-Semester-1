#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur data untuk menyimpan informasi pengguna
struct User {
    string nama;
    string email;
    string alamat;
    string username;
    string password;
};

// Struktur data untuk menyimpan informasi booking
struct Booking {
    string username;
    string layanan;
    string waktu;
    bool sudahBayar;
};

// Vektor untuk menyimpan data pengguna dan booking
vector<User> users;
vector<Booking> bookings;

// Fungsi untuk mendaftarkan pengguna baru
void daftarUser() {
    User newUser;
    cout << "Masukkan nama: ";
    getline(cin >> ws, newUser.nama);
    cout << "Masukkan email: ";
    getline(cin, newUser.email);
    cout << "Masukkan alamat: ";
    getline(cin, newUser.alamat);
    cout << "Masukkan username: ";
    getline(cin, newUser.username);
    cout << "Masukkan password: ";
    getline(cin, newUser.password);

    users.push_back(newUser);
    cout << "Pendaftaran berhasil!\n";
}

// Fungsi untuk login pengguna
bool loginUser(string &username) {
    string password;
    cout << "Masukkan username: ";
    getline(cin >> ws, username);
    cout << "Masukkan password: ";
    getline(cin, password);

    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk menampilkan menu layanan
void tampilkanLayanan() {
    cout << "Layanan yang tersedia:\n";
    cout << "1. Potong Rambut\n";
    cout << "2. Styling\n";
    cout << "3. Cuci Rambut\n";
}

// Fungsi untuk memeriksa ketersediaan waktu
bool cekKetersediaanWaktu(const string &waktu) {
    for (const auto &booking : bookings) {
        if (booking.waktu == waktu) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk melakukan booking
void lakukanBooking(const string &username) {
    Booking newBooking;
    newBooking.username = username;

    tampilkanLayanan();
    cout << "Pilih layanan (1-3): ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1:
            newBooking.layanan = "Potong Rambut";
            break;
        case 2:
            newBooking.layanan = "Styling";
            break;
        case 3:
            newBooking.layanan = "Cuci Rambut";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            return;
    }

    string waktu;
    bool waktuTersedia = false;
    do {
        cout << "Masukkan waktu booking (format: DD/MM/YYYY HH:MM): ";
        getline(cin, waktu);
        waktuTersedia = cekKetersediaanWaktu(waktu);
        if (!waktuTersedia) {
            cout << "Waktu tidak tersedia. Silakan pilih waktu lain.\n";
        }
    } while (!waktuTersedia);

    newBooking.waktu = waktu;

    cout << "Konfirmasi booking:\n";
    cout << "Layanan: " << newBooking.layanan << "\n";
    cout << "Waktu: " << newBooking.waktu << "\n";
    cout << "Apakah Anda yakin ingin melakukan booking? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;
    cin.ignore();

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        cout << "Silakan lakukan pembayaran.\n";
        cout << "Masukkan jumlah pembayaran: ";
        double pembayaran;
        cin >> pembayaran;
        cin.ignore();

        newBooking.sudahBayar = true;
        bookings.push_back(newBooking);
        cout << "Booking berhasil dilakukan dan pembayaran diterima!\n";
    } else {
        cout << "Booking dibatalkan.\n";
    }
}

// Fungsi untuk menampilkan semua booking
void tampilkanSemuaBooking() {
    cout << "Semua Data Booking:\n";
    for (const auto &booking : bookings) {
        cout << "Username: " << booking.username << ", Layanan: " << booking.layanan
             << ", Waktu: " << booking.waktu << ", Status Pembayaran: "
             << (booking.sudahBayar ? "Sudah Bayar" : "Belum Bayar") << "\n";
    }
}

// Fungsi untuk menampilkan semua data pengguna
void tampilkanSemuaPengguna() {
    cout << "Semua Data Pengguna:\n";
    for (const auto &user : users) {
        cout << "Nama: " << user.nama << ", Email: " << user.email
             << ", Alamat: " << user.alamat << ", Username: " << user.username << "\n";
    }
}

// Fungsi untuk memperbarui status pembayaran
void perbaruiStatusPembayaran() {
    string username;
    cout << "Masukkan username untuk memperbarui status pembayaran: ";
    getline(cin >> ws, username);

    for (auto &booking : bookings) {
        if (booking.username == username && !booking.sudahBayar) {
            booking.sudahBayar = true;
            cout << "Status pembayaran berhasil diperbarui untuk " << username << "\n";
            return;
        }
    }
    cout << "Booking tidak ditemukan atau sudah dibayar.\n";
}

// Fungsi utama
int main() {
    while (true) {
        cout << "\nSelamat datang di Sistem Booking Barbershop\n";
        cout << "1. Daftar\n";
        cout << "2. Login User\n";
        cout << "3. Login Admin\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                daftarUser();
                break;
            case 2: {
                string username;
                if (loginUser(username)) {
                    cout << "Login berhasil!\n";
                    while (true) {
                        cout << "\nMenu User\n";
                        cout << "1. Booking Layanan\n";
                        cout << "2. Logout\n";
                        cout << "Pilih menu (1-2): ";
                        int pilihanUser;
                        cin >> pilihanUser;
                        cin.ignore();

                        if (pilihanUser == 1) {
                            lakukanBooking(username);
                        } else if (pilihanUser == 2) {
                            break;
                        } else {
                            cout << "Pilihan tidak valid.\n";
                        }
                    }
                } else {
                    cout << "Login gagal. Username atau password salah.\n";
                }
                break;
            }
            case 3: {
                string adminUsername, adminPassword;
                cout << "Masukkan username admin: ";
                getline(cin, adminUsername);
                cout << "Masukkan password admin: ";
                getline(cin, adminPassword);

                if (adminUsername == "admin" && adminPassword == "admin123") {
                    cout << "Login admin berhasil!\n";
                    while (true) {
                        cout << "\nMenu Admin\n";
                        cout << "1. Lihat Semua Data Booking\n";
                        cout << "2. Lihat Semua Data Pengguna\n";
                        cout << "3. Perbarui Status Pembayaran\n";
                        cout << "4. Logout\n";
                        cout << "Pilih menu (1-4): ";
                        int pilihanAdmin;
                        cin >> pilihanAdmin;
                        cin.ignore();

                        switch (pilihanAdmin) {
                            case 1:
                                tampilkanSemuaBooking();
                                break;
                            case 2:
                                tampilkanSemuaPengguna();
                                break;
                            case 3:
                                perbaruiStatusPembayaran();
                                break;
                            case 4:
                                goto adminLogout;
                            default:
                                cout << "Pilihan tidak valid.\n";
                        }
                    }
                    adminLogout:;
                } else {
                    cout << "Login admin gagal.\n";
                }
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan sistem kami. Sampai jumpa!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}


