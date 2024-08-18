#include <iostream>

using namespace std;

int main()
{
	string nama[100];
	string MatKul[100];
	int nilai[100];
	int jml;

	//Input	
	cout << "Masukan Jumlah Mahasiswa: ";
	cin >> jml;
	for (int i = 1; i <= jml; i++) {
		cout << "Masukan Nama Mahasiswa: ";
		cin >> nama[i];
		cout << "Masukan MataKuliah: ";
		cin >> MatKul[i];
		cout << "Masukan Nilai Mahasiswa: ";
		cin >> nilai[i];
	}

	//Menampilkan Data
	for (int i = 1; i <= jml; i++)
	{
		cout << "\nTampilkan Data: " << endl;
		cout << "Nama" << nama[i] << "Nilai Matakuliah" << MatKul[i] << "adalah=" << nilai[i] << endl;
	}
	return 0;
}