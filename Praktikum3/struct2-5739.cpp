#include <iostream>

using namespace std;

struct Karyawan
{
	int ID;
	int Umur;
	float Gaji;
};

void inputDataKaryawan(Karyawan &target);
void cetakDataKaryawan(Karyawan &target);
float getTotalGaji(Karyawan a, Karyawan b);

int main()
{
	Karyawan joko, paijo;
	
	inputDataKaryawan (joko);
	
	inputDataKaryawan (paijo);
	
	cetakDataKaryawan (joko);
	
	cetakDataKaryawan (paijo);
	
	float TotalGaji = getTotalGaji(joko, paijo);
	cout << "Total gaji joko dan paijo : " << TotalGaji << endl << endl;
	
	system("pause");
	return 0;
}

void inputDataKaryawan(Karyawan &target)
{
	cout << "Total data karyawan" << endl;
	cout << "===================" << endl;
	cout << " ID   : ";
	cin >> target.ID;
	cout << " Umur : ";
	cin >> target.Umur;
	cout << " Gaji : ";
	cin >> target.Gaji;
	cout << endl;
}

void cetakDataKaryawan(Karyawan &target)
{
	cout << "Total data karyawan" << endl;
	cout << "===================" << endl;
	cout << " ID   : " << target.ID << endl;
	cout << " Umur : " << target.Umur << endl;
	cout << " Gaji : " << target.Gaji << endl;
	cout << endl;
}

float getTotalGaji(Karyawan a, Karyawan b)
{
	return a.Gaji + b.Gaji;
}


