#include <iostream>
using namespace std;

int main()
{
	int arr[10];
	int kiri,kanan,tengah;
	int temp, key, n;
	bool isKtm= false;
	
	cout << "Masukkan jumlah data : ";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Angka ke - ["<<i<<"] : ";
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[jS];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	cout << "Data yangg telah diurutkan adalah : ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << "\n Masukkan angka yang dicari : ";
	cin >> key;
	kiri = 0;
	kanan = n-1;
	
	while (kiri <= kanan)
	{
		tengah = (kiri + kanan ) /2;
		
		if (key == arr [tengah])
		{
			isKtm = true;
			break;
		}
		else if (key < arr [tengah])
		{
			kanan = tengah -1;
		}
		else
		{
			kiri = tengah +1;
		}
	}
	
	if (isKtm == true)
	cout << "Angka ditemukan ";
	else
	cout << "angka tidak ditemukan " << "\n" << endl;
}
