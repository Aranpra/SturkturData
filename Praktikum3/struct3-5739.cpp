#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    char npm[11];
    char nama[30];
    char alamat[100];
    float ipk;
    char tahun[5]; // Changed size to 5 to accommodate null terminator
};

int main()
{
    int jumlahMahasiswa;
    cout << "Jumlah mahasiswa yang ingin diinputkan : ";
    cin >> jumlahMahasiswa;
    cout << endl;

    Mahasiswa mhs[jumlahMahasiswa];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Data Mahasiswa ke #" << (i + 1) << endl;
        cout << " NPM : ";
        cin >> mhs[i].npm;

        cout << " Nama : ";
        cin.ignore();
        cin.getline(mhs[i].nama, 30);

        cout << " Alamat : ";
        cin.getline(mhs[i].alamat, 100);

        // Input validation for IPK
        do
        {
            cout << " IPK : ";
            cin >> mhs[i].ipk;
            if (mhs[i].ipk < 0 || mhs[i].ipk > 4.0)
            {
                cout << "IPK harus berada dalam rentang 0 hingga 4.0" << endl;
            }
        } while (mhs[i].ipk < 0 || mhs[i].ipk > 4.0);

        cout << " Tahun : ";
        cin >> mhs[i].tahun;

        cout << endl;
    }
    cout << endl;

    cout << "Laporan Data Mahasiswa" << endl;
    cout << "======================" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "No. #" << (i + 1) << endl;
        cout << " NPM    : " << mhs[i].npm << endl;
        cout << " Nama   : " << mhs[i].nama << endl;
        cout << " Alamat : " << mhs[i].alamat << endl;
        cout << " IPK    : " << mhs[i].ipk << endl;
        cout << " Tahun  : " << mhs[i].tahun << endl;

        cout << endl;
    }

    // Pause and return
    
    system("pause");
    return 0;
}
