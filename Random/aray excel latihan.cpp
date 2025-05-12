#include <iostream>
using namespace std;

int main() {
    
    string mahasiswa[9][6] = {
        {"NIM1", "Farel  ", "TIk", "TMJ", "Mars     ", "65"},
        {"NIM2", "Nugi   ", "TIK", "TMJ", "Pluto    ", "45"},
        {"NIM3", "Atpur  ", "TIK", "TMJ", "Matahari ", "52"},
        {"NIM4", "Aris   ", "TIK", "TMJ", "Bulan    ", "65"},
        {"NIM5", "Rapli  ", "TIK", "TMJ", "Saturnus ", "74"},
        {"NIM6", "Riandy ", "TIK", "TMJ", "Neptunus ", "32"},
        {"NIM7", "Ukin   ", "TIK", "TMJ", "Bumi     ", "54"},
        {"NIM8", "Salman ", "TIK", "TMJ", "Bekasi   ", "64"},
        {"NIM9", "Imam   ", "TIK", "TMJ", "Bandung  ", "87"}
    };

    cout << "NIM\t\tNama\t\tJurusan\t\tProdi\t\tAlamat\t\t\tUmur\n";
    cout << "--------------------------------------------------------------------------------\n";

    for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 6; j++) {
    	cout<<mahasiswa[i][j]<<"\t\t";
	}
        cout<<"\n";
    }

    return 0;
}

