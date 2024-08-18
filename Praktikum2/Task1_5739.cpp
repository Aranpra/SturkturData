#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Fungsi untuk menghitung jumlah kata dalam string menggunakan pointer
int hitung_jumlah_kata(string str) {
    stringstream ss(str);
    string token;
    int jumlah_kata = 0;

    // Loop untuk menghitung jumlah kata
    while (ss >> token) {
        jumlah_kata++;
    }

    return jumlah_kata;
}

int main() {
    string input_string;
    string gabungan_kata; // String untuk menyimpan kata-kata yang digabungkan

    // Input string dari pengguna
    cout << "Masukkan Kalimat: ";
    getline(cin, input_string);

    // Hitung jumlah kata dalam string dan cetak hasilnya
    int jumlah_kata = hitung_jumlah_kata(input_string);
    cout << "Jumlah kata dalam kalimat " << input_string << " adalah" << jumlah_kata;

    return 0;
}

