#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama[15] = {
        "Raffi", "Farrel", "Rapli", "Arip", "Ajis", "Sam",
        "Salman", "Aris", "Imam", "Ukin", "Dimas", "Iqbal",
        "Damar", "Rizki", "Rijal"
    };
    
    string nim[15] = {
        "2407421077", "2407421083", "2407421085", "2407421066",
        "2407421079", "2407421069", "2407421071", "2407421063",
        "2407421081", "2407421073", "2407421078", "2407421059",
        "2407421072", "2407421068", "2407421076"
    };
    
    string jurusan = "Teknik Informatika dan Komputer";
    string prodi = "Teknik Multimedia dan Jaringan";
    
    string cariNIM;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> cariNIM;

    bool ditemukan = false;
    for (int i = 0; i < 15; i++) {
        if (nim[i] == cariNIM) {
            // Jika NIM ditemukan, cetak data mahasiswa
            cout << "\nData ditemukan:\n";
            cout << "Nama    : " << nama[i] << "\n";
            cout << "NIM     : " << nim[i] << "\n";
            cout << "Jurusan : " << jurusan << "\n";
            cout << "Prodi   : " << prodi << "\n";
            ditemukan = true;
            break; // Hentikan pencarian setelah NIM ditemukan
        }
    }

    if (!ditemukan) {
        cout << "NIM tidak ditemukan dalam data.\n";
    }

    return 0;
}

