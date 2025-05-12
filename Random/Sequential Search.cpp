#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Jika tidak ditemukan
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = sequentialSearch(arr, n, key);
    if (result != -1) {
        cout << "Elemen ditemukan pada indeks: " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan dalam array.\n";
    }

    return 0;
}

