#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

// Vector untuk menyimpan daftar layanan
vector<Layanan> daftarLayanan = {
    {"Potong Rambut", 50000},
    {"Styling", 75000},
    {"Cuci Rambut", 30000}
};

// Vector untuk menyimpan data booking
vector<Booking> dataBooking;

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

int main() {
    int pilihan;

    do {
        cout << "\n=== Sistem Booking ===" << endl;
        cout << "1. Booking Layanan" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                fiturBooking();
                break;
            case 2:
                cout << "Terima kasih telah menggunakan sistem booking.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 2);

    return 0;
}

