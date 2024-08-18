#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Fungsi untuk mengubah setiap huruf menjadi huruf besar
void hurufBesar(char *string) {
    while (*string) {
        *string = toupper(*string);
        string++;
    }
}

// Fungsi untuk mengubah setiap huruf menjadi huruf kecil
void hurufKecil(char *string) {
    while (*string) {
        *string = tolower(*string);
        string++;
    }
}

// Fungsi untuk membuat huruf pertama menjadi huruf besar
void hurufPertamaBesar(char *string) {
    // Mengecek apakah karakter pertama adalah huruf
    if(isalpha(*string)) {
        *string = toupper(*string);
    }
}

int main() {
    const int MAX_LENGTH = 100;
    char string[MAX_LENGTH];

    // Input string dari pengguna
    cout << "Masukkan kalimat : ";
    cin.getline(string, MAX_LENGTH);

    // Menampilkan string asli
    cout << "String asli: " << string << endl;

    // Mengubah setiap huruf menjadi huruf besar
    char stringBesar[MAX_LENGTH];
    strcpy(stringBesar, string);
    hurufBesar(stringBesar);
    cout << "String dalam huruf besar: " << stringBesar << endl;

    // Mengubah setiap huruf menjadi huruf kecil
    char stringKecil[MAX_LENGTH];
    strcpy(stringKecil, string);
    hurufKecil(stringKecil);
    cout << "String dalam huruf kecil: " << stringKecil << endl;

    // Mengubah huruf pertama menjadi huruf besar
    char stringPertamaBesar[MAX_LENGTH];
    strcpy(stringPertamaBesar, string);
    hurufPertamaBesar(stringPertamaBesar);
    cout << "Kalimat awal huruf besar: " << stringPertamaBesar << endl;

    return 0;
}

