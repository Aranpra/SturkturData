#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

Node *head = NULL, *tail = NULL, *print = NULL, *del = NULL, *newNode = NULL;

bool isEmpty();
void insertNode(int data);
void deleteFromFront();
void printNode();

int main()
{
    while (true)
    {
        int pilihan;
        cout << "-------------------------------" << endl;
        cout << "DOUBLE LINKED LIST NON CIRCULAR" << endl;
        cout << "-------------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Menambahkan Node" << endl;
        cout << "2. Menghapus Node dari depan" << endl;
        cout << "3. Menampilkan Node" << endl;
        cout << "4. Selesai" << endl;
        cout << "-------------------------------" << endl;

        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            int data;
            cout << "Masukkan Data : ";
            cin >> data;
            insertNode(data);
            break;
        case 2:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                deleteFromFront();
            }
            break;
        case 3:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                printNode();
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Pilihan Tidak Tersedia!" << endl;
        }
    }

    return 0;
}

bool isEmpty()
{
    return head == NULL;
}

void insertNode(int data)
{
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteFromFront()
{
    int simpan;
    if (head != NULL)
    {
        if (head->next != NULL)
        {
            del = head;
            simpan = head->data;
            cout << "\n" << simpan << " telah dihapus" << endl;
            head = head->next;
            head->prev = NULL;
            delete del;
        }
        else
        {
            simpan = head->data;
            cout << "\n" << simpan << " telah dihapus" << endl;
            delete head;
            head = NULL;
            tail = NULL;
        }
    }
    else
    {
        cout << "\nLinked List kosong penghapusan tidak dapat dilakukan" << endl;
    }
}

void printNode()
{
    print = head;
    int i = 1;
    if (head != NULL)
    {
        cout << "Isi Linked List: ";
        while (print != NULL)
        {
            cout << print->data;
            if (print->next != NULL)
            {
                cout << " <=> ";
            }
            print = print->next;
        }
        cout << endl;
    }
    else
    {
        cout << "\nTidak ada data dalam linked list" << endl;
    }
}
