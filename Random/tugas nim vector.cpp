#include <iostream>
#include <vector>
using namespace std;

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
        cout << "\nMenu Operasi Data Mahasiswa:\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Ubah Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Tambah Data\n";
        cout << "5. Cari Data Berdasarkan NIM\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Tampilkan data
            if (nama.empty() || nim.empty()) {  // Periksa apakah data kosong
                cout << "Data mahasiswa kosong!\n";
            } else {
                cout << "Data Mahasiswa:\n";
                for (int i = 0; i < nama.size(); i++) {
                    cout << "Nama: " + nama[i] + "\nNIM: " + nim[i] +
                            "\nJurusan: " + jurusan +
                            "\nProdi: " + prodi + "\n\n";
                }
            }
        } else if (pilihan == 2) {
            // meminta pengguna memasukkan indeks data yang ingin diubah.
            int indeks;
            cout << "Masukkan indeks data yang ingin diubah (0-" << nama.size() - 1 << "): "; 
            cin >> indeks;
            
			// Validasi Indeks (memeriksa apakah indeks yang dimasukkan pengguna valid)
            if (indeks >= 0 && indeks < nama.size()) {
            	// Memasukkan Data Baru
                string namaBaru, nimBaru; //untuk menyimpan data baru yang dimasukkan pengguna.
                cout << "Masukkan nama baru: "; //untuk mengabaikan spasi atau newline dari input sebelumnya, agar tidak mengganggu getline
                cin >> ws; // Mengabaikan whitespace
                getline(cin, namaBaru);
                cout << "Masukkan NIM baru: ";
                getline(cin, nimBaru);
                
                // mengubah data
                nama[indeks] = namaBaru;
                nim[indeks] = nimBaru;
                cout << "Data berhasil diubah.\n";
            } else {
                cout << "Indeks tidak valid!\n";
            }
        } else if (pilihan == 3) {
            // Hapus data
            int indeks; //// Variabel 'indeks' baru dideklarasikan di sini
            //meminta pengguna memasukkan indeks elemen yang ingin dihapus.
            cout << "Masukkan indeks data yang ingin dihapus (0-" << nama.size() - 1 << "): ";
            cin >> indeks;

            if (indeks >= 0 && indeks < nama.size()) {
                nama.erase(nama.begin() + indeks); //hapus -  tujuan + indeks (untuk akses indeks)
                nim.erase(nim.begin() + indeks); ////hapus -  tujuan + indeks (untuk akses indeks)
                cout << "Data pada indeks " + to_string(indeks) + " berhasil dihapus.\n";
            } else {
                cout << "Indeks tidak valid!\n";
            }
        } else if (pilihan == 4) {
            // Tambah data
            string namaBaru, nimBaru;
            cout << "Masukkan nama baru: ";
            cin >> ws;
            getline(cin, namaBaru);
            cout << "Masukkan NIM baru: ";
            getline(cin, nimBaru);
            nama.push_back(namaBaru); //push_back menambahkan elemen baru (namaBaru) ke akhir vector nama
            nim.push_back(nimBaru); //push_back menambahkan elemen baru (nimBaru) ke akhir vector nim.
            cout << "Data baru berhasil ditambahkan.\n";
        } else if (pilihan == 5) {
            // Cari data berdasarkan NIM
            string nimDicari;
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> ws;
            getline(cin, nimDicari);

            bool ditemukan = false;
            for (int i = 0; i < nim.size(); i++) {
                if (nim[i] == nimDicari) {
                    cout << "Data Mahasiswa Ditemukan:\n";
                    cout << "Nama: " + nama[i] + "\nNIM: " + nim[i] + "\n";
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data dengan NIM " + nimDicari + " tidak ditemukan.\n";
            }
        } else if (pilihan == 6) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}
    
