#include <iostream>
#include <string>
using namespace std;

void printArray(string arr[], int n);
void insertionSortAscending(string arr[], int n);
void insertionSortDescending(string arr[], int n);

int main()
{
    int n;
    cout << "Masukan banyak Input data : ";
    cin >> n;

    string *arr = new string[n];
    cout << "Masukan Input data : \n";
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Input Nama = ";
        getline(cin, arr[i]);
    }
    
    cout << endl;
    insertionSortAscending(arr, n);
    cout << "Data yang telah diurutkan Ascending sesuai Abjad Nama : " << endl;
    printArray(arr, n);

    insertionSortDescending(arr, n); 
    cout << "Data yang telah diurutkan Descending sesuai Abjad Nama : " << endl;
    printArray(arr, n);

    delete[] arr;
    return 0;
}

void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nama = " << arr[i] <<  endl;
    }
    cout << endl;
}

void insertionSortAscending(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            // Memindahkan elemen yang lebih besar dari key ke posisi satu di depannya
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && key > arr[j]) { // Mengubah logika perbandingan agar mengurutkan secara descending
            // Memindahkan elemen yang lebih kecil dari key ke posisi satu di depannya
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
