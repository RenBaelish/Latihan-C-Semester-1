#include <iostream>
#include <string>
using namespace std;

// Maksimum jumlah data
const int MAX_USERS = 10;
const int MAX_LAYANAN = 3;
const int MAX_BOOKING = 10;

// Database array
struct User {
    int id;
    string username;
    string password;
    string alamat;
    string noHp;
};

struct Layanan {
    int id;
    string namaLayanan;
    int harga;
};

struct Booking {
    int idUser;
    int idLayanan;
    bool statusPembayaran;
    bool statusBooking;
};

User pengguna[MAX_USERS];
Layanan layanan[MAX_LAYANAN] = {
    {1, "Potong Rambut", 20000},
    {2, "Styling", 15000},
    {3, "Cuci Rambut", 10000}
};

Booking bookings[MAX_BOOKING];
int jumlahPengguna = 0;
int jumlahBooking = 0;

// Data admin
string adminUsername = "admin";
string adminPassword = "admin123";

// Fungsi daftar akun baru
void daftarAkunBaru() {
    if (jumlahPengguna >= MAX_USERS) {
        cout << "Kuota pengguna penuh!\n";
        return;
    }

    string username, password, alamat, noHp;
    cout << "\n[DAFTAR AKUN BARU]\n";

    cout << "Masukkan Username: ";
    cin.ignore(); // Membersihkan buffer sebelum getline
    getline(cin, username); // Menggunakan getline agar dapat menangkap teks dengan spasi

    cout << "Masukkan Password: ";
    cin >> password; // Tidak ada spasi, cukup menggunakan cin
    cin.ignore(); // Bersihkan buffer setelah cin

    cout << "Masukkan Alamat: ";
    getline(cin, alamat); // Gunakan getline untuk alamat dengan spasi

    cout << "Masukkan Nomor HP: ";
    cin >> noHp; // Tidak ada spasi, cukup menggunakan cin

    // Simpan data ke array pengguna
    pengguna[jumlahPengguna] = {jumlahPengguna + 1, username, password, alamat, noHp};
    jumlahPengguna++;
    cout << "Pendaftaran berhasil! Silakan login.\n";
}


// Fungsi login
int loginUser() {
    string username, password;
    cout << "\n[LOGIN]\n";
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    // Cek login sebagai pengguna
    for (int i = 0; i < jumlahPengguna; i++) {
        if (pengguna[i].username == username && pengguna[i].password == password) {
            cout << "Login berhasil! Selamat datang, " << pengguna[i].username << ".\n";
            return pengguna[i].id; // Mengembalikan id pengguna
        }
    }
    // Cek login sebagai admin
    if (username == adminUsername && password == adminPassword) {
        cout << "Login Admin berhasil!\n";
        return -2; // Kode khusus untuk login admin
    }

    cout << "Login gagal! Username atau password salah.\n";
    return -1;
}

// Fungsi booking layanan
void booking(int idPengguna) {
    if (idPengguna < 1) {
        cout << "Anda harus login untuk melakukan booking.\n";
        return;
    }

    cout << "\n[BOOKING LAYANAN]\n";
    cout << "Daftar Layanan:\n";
    for (int i = 0; i < MAX_LAYANAN; i++) {
        cout << layanan[i].id << ". " << layanan[i].namaLayanan << " - Rp." << layanan[i].harga << "\n";
    }

    int pilihanLayanan;
    cout << "Pilih ID Layanan: ";
    cin >> pilihanLayanan;

    if (pilihanLayanan < 1 || pilihanLayanan > MAX_LAYANAN) {
        cout << "ID Layanan tidak valid!\n";
        return;
    }

    char konfirmasi;
    cout << "Anda memilih " << layanan[pilihanLayanan - 1].namaLayanan
         << " seharga Rp." << layanan[pilihanLayanan - 1].harga << ". Konfirmasi booking? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        char konfirmasiPembayaran;
        cout << "Konfirmasi pembayaran? (y/n): ";
        cin >> konfirmasiPembayaran;
        if (konfirmasiPembayaran == 'y' || konfirmasiPembayaran == 'Y') {
            // Simpan booking
            bookings[jumlahBooking] = {idPengguna, pilihanLayanan, true, true};
            jumlahBooking++;
            cout << "Pembayaran berhasil. Booking selesai.\n";
        } else {
            cout << "Pembayaran dibatalkan.\n";
        }
    } else {
        cout << "Booking dibatalkan.\n";
    }
}

// Fungsi melihat katalog layanan
void lihatKatalog() {
    cout << "\n[KATALOG LAYANAN]\n";
    for (int i = 0; i < MAX_LAYANAN; i++) {
        cout << layanan[i].id << ". " << layanan[i].namaLayanan << " - Rp." << layanan[i].harga << "\n";
    }
}

// Fungsi mengelola data booking
void mengelolaBooking() {
    cout << "\n[MENGELOLA DATA BOOKING]\n";
    
    if (jumlahBooking == 0) {
        cout << "Tidak ada data booking.\n";
        return;
    }

    // Menampilkan daftar booking
    for (int i = 0; i < jumlahBooking; i++) {
        cout << "ID Booking: " << i + 1
             << ", User ID: " << bookings[i].idUser
             << ", Layanan: " << layanan[bookings[i].idLayanan - 1].namaLayanan
             << ", Pembayaran: " << (bookings[i].statusPembayaran ? "Lunas" : "Belum")
             << ", Status Booking: " << (bookings[i].statusBooking ? "Terverifikasi" : "Belum Terverifikasi")
             << endl;
    }

    // Memilih booking untuk dikelola
    int idBooking;
    cout << "\nMasukkan ID Booking yang ingin dikelola: ";
    cin >> idBooking;

    if (idBooking < 1 || idBooking > jumlahBooking) {
        cout << "ID Booking tidak valid!\n";
        return;
    }

    Booking &bookingDipilih = bookings[idBooking - 1];

    // Menampilkan detail booking
    cout << "\n[DETAIL BOOKING]\n";
    cout << "ID Booking: " << idBooking
         << ", User ID: " << bookingDipilih.idUser
         << ", Layanan: " << layanan[bookingDipilih.idLayanan - 1].namaLayanan
         << ", Pembayaran: " << (bookingDipilih.statusPembayaran ? "Lunas" : "Belum")
         << ", Status Booking: " << (bookingDipilih.statusBooking ? "Terverifikasi" : "Belum Terverifikasi")
         << endl;

    // Opsi untuk mengelola status pembayaran dan status booking
    char pilihan;
    cout << "\nApakah Anda ingin mengubah status pembayaran? (y/n): ";
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y') {
        bookingDipilih.statusPembayaran = true;
        cout << "Status pembayaran berhasil diubah menjadi Lunas.\n";
    }

    cout << "Apakah Anda ingin mengubah status booking menjadi Terverifikasi? (y/n): ";
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y') {
        bookingDipilih.statusBooking = true;
        cout << "Status booking berhasil diubah menjadi Terverifikasi.\n";
    }
}


/// Fungsi melihat data pelanggan
void lihatDataPelanggan() {
    cout << "\n[DATA PELANGGAN]\n";
    for (int i = 0; i < jumlahPengguna; i++) {
        cout << "ID: " << pengguna[i].id << ", Username: " << pengguna[i].username
             << ", Alamat: " << pengguna[i].alamat << ", No HP: " << pengguna[i].noHp;
        
        // Cek apakah user memiliki booking
        bool hasBooking = false;
        for (int j = 0; j < jumlahBooking; j++) {
            if (bookings[j].idUser == pengguna[i].id) {
                hasBooking = true;
                // Menampilkan informasi booking dan status pembayaran
                cout << ", Booking: " << layanan[bookings[j].idLayanan - 1].namaLayanan
                     << ", Pembayaran: " << (bookings[j].statusPembayaran ? "Lunas" : "Belum Lunas")
                     << ", Status Booking: " << (bookings[j].statusBooking ? "Terverifikasi" : "Belum Terverifikasi") << endl;
                break; // Keluar dari loop setelah menemukan booking pertama
            }
        }

        if (!hasBooking) {
            // Jika user belum memiliki booking
            cout << ", Belum ada booking, Status Pembayaran: Tidak ada" << endl;
        }
    }
}



// Fungsi mengelola laporan
void kelolaLaporan() {
    cout << "\n[MENGELOLA LAPORAN]\n";

    if (jumlahBooking == 0) {
        cout << "Belum ada transaksi yang tercatat.\n";
        return;
    }

    for (int i = 0; i < jumlahBooking; i++) {
        cout << "ID Booking: " << i + 1
             << ", User ID: " << bookings[i].idUser
             << ", Layanan: " << layanan[bookings[i].idLayanan - 1].namaLayanan
             << ", Pembayaran: " << (bookings[i].statusPembayaran ? "Lunas" : "Belum")
             << ", Status Booking: " << (bookings[i].statusBooking ? "Terverifikasi" : "Belum Terverifikasi")
             << endl;
    }
}

// Fungsi menu utama pengguna
void menuUser(int idPengguna) {
    int pilihan;
    do {
        cout << "\n[MENU UTAMA]\n";
        cout << "1. Booking Layanan\n2. Melihat Katalog Layanan\n3. Log Out\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            booking(idPengguna);
        } else if (pilihan == 2) {
            lihatKatalog();
        } else if (pilihan == 3) {
            cout << "Anda telah log out.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

// Fungsi menu admin
void menuAdmin() {
    int pilihan;
    do {
        cout << "\n[MENU ADMIN]\n";
        cout << "1. Mengelola Data Booking\n2. Melihat Data Pelanggan\n3. Mengelola Laporan\n4. Log Out\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            mengelolaBooking();
        } else if (pilihan == 2) {
            lihatDataPelanggan();
        } else if (pilihan == 3) {
            kelolaLaporan();
        } else if (pilihan == 4) {
            cout << "Anda telah log out.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

// Program utama
int main() {
    int idPengguna = -1;

    while (true) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Login\n2. Daftar Akun Baru\n3. Keluar\n";
        int pilihan;
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int loginResult = loginUser();
            if (loginResult == -1) {
                continue; // Jika login gagal, kembali ke menu utama
            } else if (loginResult == -2) {
                menuAdmin(); // Login sebagai admin
            } else {
                menuUser(loginResult); // Login sebagai pengguna
            }
        } else if (pilihan == 2) {
            daftarAkunBaru();
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan layanan kami.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

