#include <iostream>
#include <algorithm>

using namespace std;

// Fungsi untuk mengurutkan array secara descending
void sortDescending(int *array, int size) {
    sort(array, array + size, greater<int>());
}

// Fungsi untuk mencari nilai dalam array menggunakan pointer
bool findValue(int *array, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (*array == value) {
            return true;
        }
        array++;
    }
    return false;
}

int main() {
    const int MAX_SIZE = 100;
    int nilai[MAX_SIZE];
    int ukuran;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> ukuran;

    // Meminta pengguna untuk memasukkan nilai ke dalam array
    cout << "Masukkan nilai-nilai:\n";
    for (int i = 0; i < ukuran; ++i) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    // Mengurutkan nilai secara descending
    sortDescending(nilai, ukuran);

    // Menampilkan nilai setelah diurutkan
    cout << "\nNilai setelah diurutkan secara descending:\n";
    for (int i = 0; i < ukuran; ++i) {
        cout << nilai[i] << " ";
    }
    cout << endl;

    // Meminta nilai yang dicari dari pengguna
    int nilaiDicari;
    cout << "\nMasukkan nilai yang ingin Anda cari: ";
    cin >> nilaiDicari;

    // Mencari nilai yang dimasukkan oleh pengguna
    bool ditemukan = findValue(nilai, ukuran, nilaiDicari);
    if (ditemukan) {
        cout << "Nilai " << nilaiDicari << " ditemukan dalam array.\n";
    } else {
        cout << "Nilai " << nilaiDicari << " tidak ditemukan dalam array.\n";
    }

    return 0;
}

