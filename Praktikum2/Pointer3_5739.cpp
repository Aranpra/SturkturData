#include <iostream>
using namespace std;

int main()
{
	int umur[] = { 21, 22, 23, 24, 25 };
	
	int *ptrUmur = umur;
	
	cout << "Alamat umur[0] = " << &umur[0] << endl;
	cout << "Alamat umur[1] = " << &umur[1] << endl;
	cout << "Alamat umur[2] = " << &umur[2] << endl;
	cout << "Alamat umur[3] = " << &umur[3] << endl;
	cout << "Alamat umur[4] = " << &umur[4] << endl << endl;
	
	cout << "Nilai ptrUmur = " << ptrUmur << " sama dengan alamat umur[0] (" << &umur[0] << ")" << endl;
	
	ptrUmur += 3;
	cout << "Niali ptrUmur = " << ptrUmur << " sama dengan nilai umur[3] (" << &umur[3] << ")" << endl;
	
	ptrUmur -= 2;
	cout << "Niali ptrUmur = " << ptrUmur << " sama dengan nilai umur[1] (" << &umur[1] << ")" << endl;
	
	cout << endl;
	system("pause");
	return 0;
}
