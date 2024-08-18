#include <iostream>

using namespace std;

struct Program
{
	char nama[50];
};
int main()
{
	int namaStruktur;
	cout<< " Dasar Struktur Data itu ada : ";
	cin>> namaStruktur;
	cout << endl;
	Program* program = new Program[namaStruktur];
	for (int i = 0; i < namaStruktur; i++)
	{
		cout << "Struktur Data " << (i + 1) << " = ";
		cin >> program[i].nama;
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
