#include <iostream>
using namespace std;

void printArray(int arr[], int n); // Deklarasi fungsi printArray
void insertionSort(int arr[], int n); // Deklarasi fungsi insertionSort

int main() {
    int arr[] = {9, 5, 1, 4, 3}; // Deklarasi variabel
    int n = sizeof(arr) / sizeof(int);
    cout << "Sebelum Array di sorting: ";
    printArray(arr, n);
    insertionSort(arr, n); // Memanggil fungsi insertion sort
    cout << "Setelah Array di sorting: ";
    printArray(arr, n);
    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            // Memindahkan elemen yang lebih besar dari key ke posisi satu di depannya
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

