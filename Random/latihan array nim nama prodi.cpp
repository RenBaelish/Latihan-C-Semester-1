#include <iostream>
#include <vector>
#include <limits>  // Tambahkan pustaka limits untuk numeric_limits
using namespace std;

void tampilkanData(const vector<string>& nama, const vector<string>& nim, const string& jurusan, const string& prodi) {
    for (int i = 0; i < nama.size(); i++) {
        cout << "Nama: " << nama[i] << "\nNIM: " << nim[i] 
             << "\nJurusan: " << jurusan 
             << "\nProdi: " << prodi << "\n\n";
    }
}

int main() {
    vector<string> nama = {
        "Raffi", "Farrel", "Rapli", "Arip", "Ajis", "Sam",
        "Salman", "Aris", "Imam", "Ukin", "Dimas", "Iqbal",
        "Damar", "Rizki", "Rijal"
    };
    
    vector<string> nim = {
        "2407421077", "2407421083", "2407421085", "2407421066",
        "2407421079", "2407421069", "2407421071", "2407421063",
        "2407421081", "2407421073", "2407421078", "2407421059",
        "2407421072", "2407421068", "2407421076"
    };
    
    string jurusan = "Teknik Informatika dan Komputer";
    string prodi = "Teknik Multimedia dan Jaringan";
    int pilihan;

    do {
        cout << "\nMenu Operasi Data Mahasiswa:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Ubah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Tambah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        // Cek jika input tidak valid
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan input
            cout << "Input tidak valid! Masukkan angka." << endl;
            continue;
        }

        if (pilihan == 1) {
            // Tampilkan data
            cout << "\nData Mahasiswa:\n";
            tampilkanData(nama, nim, jurusan, prodi);
        } 
        else if (pilihan == 2) {
            // Ubah data
            int indeks;
            cout << "Masukkan indeks data yang ingin diubah (0-" << nama.size() - 1 << "): ";
            cin >> indeks;

            if (indeks >= 0 && indeks < nama.size()) {
                string namaBaru, nimBaru;
                cout << "Masukkan nama baru: ";
                cin >> ws;  // Mengabaikan whitespace
                getline(cin, namaBaru);
                cout << "Masukkan NIM baru: ";
                getline(cin, nimBaru);
                nama[indeks] = namaBaru;
                nim[indeks] = nimBaru;
                cout << "Data berhasil diubah." << endl;
            } else {
                cout << "Indeks tidak valid!" << endl;
            }
        } 
        else if (pilihan == 3) {
            // Hapus data
            int indeks;
            cout << "Masukkan indeks data yang ingin dihapus (0-" << nama.size() - 1 << "): ";
            cin >> indeks;

            if (indeks >= 0 && indeks < nama.size()) {
                nama.erase(nama.begin() + indeks);
                nim.erase(nim.begin() + indeks);
                cout << "Data pada indeks " << indeks << " berhasil dihapus." << endl;
            } else {
                cout << "Indeks tidak valid!" << endl;
            }
        } 
        else if (pilihan == 4) {
            // Tambah data
            string namaBaru, nimBaru;
            cout << "Masukkan nama baru: ";
            cin >> ws;
            getline(cin, namaBaru);
            cout << "Masukkan NIM baru: ";
            getline(cin, nimBaru);
            nama.push_back(namaBaru);
            nim.push_back(nimBaru);
            cout << "Data baru berhasil ditambahkan." << endl;
        } 
        else if (pilihan == 5) {
            cout << "Keluar dari program." << endl;
        } 
        else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
