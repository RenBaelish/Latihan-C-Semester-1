#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Inisialisasi vector dengan beberapa mobil
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda", "KIA", "Hyundai"};
    
    // Menampilkan daftar mobil awal
    cout << "Daftar mobil awal:\n";
    for (int i = 0; i < cars.size(); i++) {
        cout << i + 1 << ". " << cars[i] << endl;
    }

    // Pencarian mobil
    string mobil_baru;
    bool ketemu = false; // Menandakan apakah mobil ditemukan
    int index_mobil = -1; // Variabel untuk menyimpan indeks mobil yang ditemukan

    cout << "\nMasukkan mobil yang ingin dicari: ";
    getline(cin, mobil_baru);

    // Mencari mobil dalam vector
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i] == mobil_baru) { // Jika mobil ditemukan
            ketemu = true;
            index_mobil = i; // Simpan indeks mobil yang ditemukan
            break;
        }
    }

    // Jika mobil ditemukan
    if (ketemu) {
        cout << "Mobil " << mobil_baru << " ditemukan!" << endl;

        // Menanyakan apakah ingin mengubah nama mobil
        char ubah;
        cout << "Apakah Anda ingin mengubah nama mobil ini? (y/n): ";
        cin >> ubah;
        cin.ignore(); // Menghapus karakter newline yang tertinggal di buffer

        if (ubah == 'y' || ubah == 'Y') {
            string mobil_baru_nama;
            cout << "Masukkan nama mobil baru: ";
            getline(cin, mobil_baru_nama); // Input nama mobil baru

            // Mengubah nama mobil dalam vector
            cars[index_mobil] = mobil_baru_nama;
            cout << "Nama mobil telah diubah menjadi: " << cars[index_mobil] << endl;
        }
    } else {
        cout << "Mobil tidak ditemukan!" << endl;
    }

    // Menanyakan apakah ingin menambah mobil baru
    char tambah;
    cout << "\nApakah Anda ingin menambah mobil baru ke daftar? (y/n): ";
    cin >> tambah;
    cin.ignore(); // Menghapus karakter newline yang tertinggal di buffer

    if (tambah == 'y' || tambah == 'Y') {
        string mobil_baru_tambah;
        cout << "Masukkan nama mobil baru: ";
        getline(cin, mobil_baru_tambah); // Input nama mobil baru

        // Menambahkan mobil baru ke vector
        cars.push_back(mobil_baru_tambah);

        cout << "Mobil baru telah ditambahkan!" << endl;
    }

    // Menampilkan daftar mobil setelah perubahan dan penambahan
    cout << "\nDaftar mobil setelah perubahan dan penambahan:\n";
    for (int i = 0; i < cars.size(); i++) {
        cout << i + 1 << ". " << cars[i] << endl;
    }

    return 0;
}

