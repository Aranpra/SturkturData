#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK = 4;

struct Stack
{
	int top;
	string data[MAX_STACK];
};

//prototipe fungsi stack
void inisialisasi();
void push(string data);
void pop();
void clear();
bool isEmpty();
bool isFull();
void print();

Stack stack;

int main()
{
	//inisialisasi
	inisialisasi();
	
	int pilihanMenu;
	string data;
	
	do
	{
		cout << ">>> PILIHAN MENU STACK <<<" << endl << endl;
		cout << "1. Menambahkan Item Stack" << endl;
		cout << "2. Menghapus Item Stack" << endl;
		cout << "3. Menampilkan Item Stack" << endl;
		cout << "4. Mengosongkan stack" << endl;
		cout << "5. Selesai" << endl << endl;
		
		cout << "Masukkan Pilihan Anda: "; cin >> pilihanMenu;
		cout << endl;
		
		switch (pilihanMenu)
		{
			case 1:
				if (isFull())
				{
					cout << "Stack sudah penuh" << endl << endl;	
				}
				else
				{
					cout << "Masukkan Data : "; 
					cin.ignore();
					getline(cin, data);
					push(data);
				}
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				if (isEmpty())
				{
					cout << "Stack Masih Kosong" << endl << endl;
				}
				else
				{
					print();
				}
				break;
			
			case 4:
				clear();
				break;
			
			case 5:
				break;
				
			default:
				cout << "Pilihan tidak tersedia" << endl << endl;
				break;
		}
	} while (pilihanMenu != 5);
	
	cout << endl;
	
	system("pause");
	
	return 0;
	
}

void inisialisasi()
{
	stack.top = -1;
}

void push(string data)
{
	stack.top++;
	stack.data[stack.top] = data;
	cout << "Data berhasil ditambahkan" << endl << endl;
}

void pop()
{
	if (isEmpty())
	{
		cout << "Stack sudah kosong" << endl << endl;
	}
	else
	{
		cout << "Data " << stack.data[stack.top] << " sudah dihapus" << endl << endl;
		stack.top--;
	}
}

void clear()
{
	stack.top = -1;
	cout << "Stack sudah kosong" << endl << endl;
}

bool isEmpty()
{
	return (stack.top == -1);
}

bool isFull()
{
	return (stack.top >= (MAX_STACK -1));
}

void print()
{
	cout << "Isi Stack" << endl << endl;
	for (int i = stack.top; i >= 0; i--)
	{
		cout << stack.data[i] << endl;
	}
	cout << endl << endl;
}
