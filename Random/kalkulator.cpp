#include <iostream>
using namespace std;

int main() {
    char operasi;
    double num1, num2;

    cout << "Masukkan operasi (+, -, *, /): ";
    cin >> operasi;
    cout << "Masukkan dua angka: ";
    cin >> num1 >> num2;

    switch (operasi) {
        case '+':
            cout << "Hasil: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Hasil: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Hasil: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Hasil: " << num1 / num2 << endl;
            else
                cout << "Error: Pembagian dengan nol tidak diizinkan." << endl;
            break;
        default:
            cout << "Operasi tidak valid." << endl;
            break;
    }
    return 0;
}

