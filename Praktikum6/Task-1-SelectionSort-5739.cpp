#include <iostream>
using namespace std;

void print(int arr[], int n); // Deklarasi fungsi print
void selectionSort(int arr[], int n); // Deklarasi fungsi selectionSort

int main() {
    int n;
    cout << "Masukan data : ";
    cin >> n;
    
    int arr[n];
    cout << "Masukan data : \n";
    for (int i = 0; i < n; i++)
    {
    	cout << " > "; cin >> arr[i];
	}

    cout << "Sebelum Array di sorting: ";
    print(arr, n);

    selectionSort(arr, n); // Memanggil fungsi selection sort

    cout << "Setelah Array di sorting: ";
    print(arr, n);

    return 0;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], int n) {
    int i, j, min_in;

    for (i = 0; i < n - 1; i++) { // satu persatu akan disorting data arraynya
        min_in = i; // menemukan elemen min dalam array yang tidak disortir
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_in])
                min_in = j;
        }
        swap(arr[i], arr[min_in]); // Menukar elemen min yang ditemukan dengan elemen pertama
    }
}

