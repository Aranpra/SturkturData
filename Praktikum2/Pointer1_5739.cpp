#include <iostream>
using namespace std;

int main()
{
	int x = 100;
	int *ptrX, *ptrY;
	
	ptrX = &x;
	ptrY = &x;
	
	*ptrX = x;
	*ptrY = x;
	
	cout << "Isi Variabel X = " << x << " ada di alamat " << &x << endl;
	cout << endl;
	
	cout << "Isi variabel ptrX = " << &x << " sama dengan alamat x " << "<" << &x << ">" << endl;
	cout << "Isi variabel ptrX = " << &x << " sama dengan alamat x "<< "<" << &x << ">" << endl;
	cout << endl;
	
	cout << "Nilai yg ditunjuk ptrX = " << *ptrX << " sama dengan niai x " << "<" << *ptrX << ">" << endl;
	cout << "Nilai yg ditunjuk ptrY = " << *ptrY << " sama dengan nilai x " << "<" << *ptrY << ">" << endl;
	cout << endl;
}
