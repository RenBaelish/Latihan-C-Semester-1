#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element tidak ditemukan
}

int main() {
    vector<int> data = {10, 22, 34, 47, 53, 64, 78, 89};
    int target;

    cout << "Data yang tersedia: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int result = binarySearch(data, target);
    if (result != -1)
        cout << "Angka ditemukan di indeks " << result << endl;
    else
        cout << "Angka tidak ditemukan." << endl;

    return 0;
}

