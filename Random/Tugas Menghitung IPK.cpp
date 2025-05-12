#include <iostream>
#include <string>
using namespace std;

int main() {
    // Data mata kuliah untuk semester 1 dan semester 2
    string matKul[2][2] = {
        {"Matematika Diskrit", "Jaringan Komputer"},
        {"Bahasa Indonesia ", "PTIK            "}
    };

    string ipk, hurufMutu;
    
    // Data nilai mahasiswa, masing-masing mahasiswa memiliki nilai untuk 2 semester
    int dataMahasiswa[5][2][2] = {
        // Mahasiswa 1
        {
            {89, 90}, {97, 90}
        },
        // Mahasiswa 2
        {
            {90, 91}, {86, 84}
        },
        // Mahasiswa 3
        {
            {83, 87}, {89, 85}
        },
        // Mahasiswa 4
        {
            {88, 86}, {84, 83}
        },
        // Mahasiswa 5
        {
            {91, 90}, {85, 87}
        }
    };

    float rataSemester, rataSemua;

    // Loop untuk setiap mahasiswa
    for (int x = 0; x < 5; x++) {
        cout << "========== Mahasiswa " << x + 1 << " ==========" << endl;
        rataSemua = 0; // Reset nilai rata-rata seluruh semester setiap kali mahasiswa berganti

        // Loop untuk semester
        for (int y = 0; y < 2; y++) {
            rataSemester = 0; // Reset nilai rata-rata semester
            // Loop untuk mata kuliah di setiap semester
            for (int z = 0; z < 2; z++) {
                rataSemester += dataMahasiswa[x][y][z]; // Menambahkan nilai setiap mata kuliah
                cout << matKul[y][z] << " "; // Menampilkan nama mata kuliah
                cout << "Semester " << y + 1 << " Nilai " << dataMahasiswa[x][y][z] << endl; // Menampilkan nilai mata kuliah
            }

            rataSemester /= 2; // Menghitung rata-rata semester (2 mata kuliah per semester)
            rataSemua += rataSemester; // Menambahkan rata-rata semester ke rata-rata keseluruhan
            cout << "Rata-rata semester " << y + 1 << ": " << rataSemester << endl << endl;
        }

        rataSemua /= 2; // Menghitung rata-rata nilai seluruh semester
        cout << "Rata-rata seluruh semester: " << rataSemua << endl;

        // Menentukan IPK dan Huruf Mutu berdasarkan rata-rata seluruh semester
        if (rataSemua >= 81) { ipk = "4"; hurufMutu = "A"; }
        else if (rataSemua >= 76) { ipk = "3.7"; hurufMutu = "A-"; }
        else if (rataSemua >= 72) { ipk = "3.3"; hurufMutu = "B"; }
        else if (rataSemua >= 68) { ipk = "3"; hurufMutu = "B-"; }
        else if (rataSemua >= 64) { ipk = "2.7"; hurufMutu = "C"; }
        else if (rataSemua >= 60) { ipk = "2.3"; hurufMutu = "C-"; }
        else if (rataSemua >= 56) { ipk = "2"; hurufMutu = "D"; }
        else if (rataSemua >= 41) { ipk = "1"; hurufMutu = "D-"; }
        else { ipk = "0"; hurufMutu = "E"; }

        // Menampilkan IPK dan Huruf Mutu
        cout << "IPK = " << ipk << endl;
        cout << "Huruf Mutu = " << hurufMutu << endl;
        cout << endl;

        rataSemua = 0; // Reset rata-rata untuk mahasiswa berikutnya
    }

    return 0;
}

