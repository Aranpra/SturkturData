#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;

bool isEmpty()
{
    return (headNode == NULL);
}

void InsertNode(string data)
{
    Node *newNode = new Node;
    newNode->data = data;

    if (isEmpty())
    {
        headNode = newNode;
    }
    else
    {
        currentNode->next = newNode;
    }
    currentNode = newNode;
    currentNode->next = NULL;
    cout << "Data Berhasil Diinputkan!" << endl;
}

void DeleteFromFront()
{
    if (!isEmpty())
    {
        Node* temp = headNode;
        headNode = headNode->next;
        delete temp;
        currentNode = headNode;
        cout << "Data Depan Berhasil Dihapus!" << endl;
    }
    else
    {
        cout << "Data Kosong!" << endl;
    }
}

void DeleteFromEnd()
{
    if (isEmpty())
    {
        cout << "Data Kosong!" << endl;
        return;
    }

    if (headNode == currentNode)
    {
        delete headNode;
        headNode = NULL;
        currentNode = NULL;
        cout << "Data Belakang Berhasil Dihapus!" << endl;
        return;
    }

    Node *bantu = headNode;
    while (bantu->next != currentNode)
    {
        bantu = bantu->next;
    }

    delete currentNode;
    currentNode = bantu;
    currentNode->next = NULL;
    cout << "Data Belakang Berhasil Dihapus!" << endl;
}

void DeleteAll()
{
    Node *bantu, *hapus;
    bantu = headNode;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    headNode = NULL;
    currentNode = NULL;
    cout << "Clear" << endl;
}

void printNode()
{
    Node *First = headNode;
    int i = 1;
    while (First != NULL)
    {
        cout << "Data : " << i << " = " << First->data << endl;
        First = First->next;
        i++;
    }
}

int main()
{
    int pilihan;
    string data;

    do
    {
        system("cls");
        printNode();
        cout << ">>> PILIHAN MENU SINGLY LINKED LIST <<<" << endl;
        cout << "1. Menambahkan Node" << endl;
        cout << "2. Menghapus Node dari Depan" << endl;
        cout << "3. Menghapus Node dari Belakang" << endl;
        cout << "4. Hapus Semua" << endl;
        cout << "5. Menampilkan Node" << endl;
        cout << "6. Selesai" << endl;
       
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) 
        {
        case 1:
            cout << "Masukkan Data : ";
            cin >> data;
            getline(cin, data);
            InsertNode(data);
            break;
        case 2:
            DeleteFromFront();
            break;
        case 3:
            DeleteFromEnd();
            break;
        case 4:
            DeleteAll();
            break;
        case 5:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                printNode();
            }
            break;
        case 6:
            cout << "Selesai!" << endl;
            break;
        default:
            cout << "Pilihan Tidak Tersedia!" << endl;
        }
        cout << "Tekan sembarang tombol untuk melanjutkan...";
        cin.ignore();
        cin.get();
    } while (pilihan != 6);
    return 0;
}

