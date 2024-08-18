#include <iostream>
#include <string>
#include <algorithm> // Untuk pengurutan menggunakan sort()
using namespace std;

int binarySearch(string arr[], int n, string key) {
    int kiri = 0;
    int kanan = n - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == key)
            return tengah;
        if (arr[tengah] < key)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1; // Jika tidak ditemukan
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    string arr[n];

    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nama di Index ke-" << i << ": ";
        getline(cin, arr[i]);
    }
    cout << endl;

    sort(arr, arr + n); // Mengurutkan array

    cout << "Data yang telah diurutkan adalah: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;

    string key;
    cout << "Masukkan Nama yang dicari: ";
    getline(cin, key);

    int index = binarySearch(arr, n, key);
    if (index != -1) {
        cout << "Nama ditemukan pada Index ke-" << index << endl;
    } else {
        cout << "Nama tidak ditemukan" << endl;
    }

    return 0;
}

