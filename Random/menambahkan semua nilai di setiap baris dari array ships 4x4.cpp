#include <iostream>
using namespace std;

int main() {
    // Array 4x4 yang diberikan
    int ships[4][4] = {
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 }
    };

    // Variabel untuk menyimpan jumlah nilai di setiap baris
    int sum;

    // Loop untuk menjumlahkan nilai di setiap baris
    for (int i = 0; i < 4; i++) {
        sum = 0; // Reset nilai sum untuk setiap baris
        for (int j = 0; j < 4; j++) {
            sum += ships[i][j]; // Tambahkan nilai di baris i kolom j
        }
        // Tampilkan hasil jumlah untuk baris ke-i
        cout << "Jumlah nilai di baris " << i + 1 << " adalah: " << sum << endl;
    }

    return 0;
}

