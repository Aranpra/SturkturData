#include <iostream>

using namespace std;

struct karyawan
{
	int karyawanID;
	int umur;
	float gaji;
};


int main()
{
	karyawan joko;
	joko.karyawanID = 10;
	joko.umur =25;
	joko.gaji = 24.15;
	
	karyawan paijo = { 11, 26, 28.23 };
	
	float totalGaji = joko.gaji + paijo.gaji;
	cout << "Total gaji joko dan paijo = " << totalGaji << endl;
	
	if (paijo.gaji > joko.gaji)
	cout << "Gaji paijo lebih besar dari joko" << endl;
	
	joko.gaji += 2.5;
	cout << "Gaji joko setelah kenaikan gaji = " << joko.gaji << endl << endl;
	
	system("pause");
	return 0;
}
