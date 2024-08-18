#include <iostream>
#include <string>
using namespace std;

void printArray(string arr[], int n);
void insertionSortAscending(string arr[], int n);
void insertionSortDescending(string arr[], int n);
int binarySearch(string arr[], int l, int r, string x);

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
    cout << "Setelah Array di sorting secara ascending: " << endl;
    printArray(arr, n);

    insertionSortDescending(arr, n); 
    cout << "Setelah Array di sorting secara descending: " << endl;
    printArray(arr, n);

    string searchName;
    cout << "Masukkan nama yang ingin dicari: ";
    getline(cin, searchName);

    // Pilih metode pencarian sesuai dengan kebutuhan (ascending atau descending)
    int searchResult;
    char choice;
    cout << "Pilih urutan pengurutan (A = Ascending, D = Descending): ";
    cin >> choice;
    if (choice == 'A' || choice == 'a') {
        insertionSortAscending(arr, n);
        searchResult = binarySearch(arr, 0, n - 1, searchName);
    } else if (choice == 'D' || choice == 'd') {
        insertionSortDescending(arr, n);
        searchResult = binarySearch(arr, 0, n - 1, searchName);
    } else {
        cout << "Pilihan tidak valid." << endl;
        return 1;
    }

    if (searchResult == -1)
        cout << "Nama tidak ditemukan." << endl;
    else
        cout << "Nama ditemukan pada indeks ke-" << searchResult << endl;

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

int binarySearch(string arr[], int l, int r, string x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

