#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

Node *head = NULL, *tail = NULL, *print = NULL, *del = NULL, *newNode = NULL;

bool isEmpty();
void insertFromFront(int data);
void insertFromBack(int data);
void deleteFromFront();
void deleteFromBack();
void insertAfter(int key, int data);
void deleteNode(int key);
void deleteAll();
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
        cout << "1. Menambahkan Node dari Depan" << endl;
        cout << "2. Menambahkan Node dari Belakang" << endl;
        cout << "3. Menghapus Node dari Depan" << endl;
        cout << "4. Menghapus Node dari Belakang" << endl;
        cout << "5. Menyisipkan Node dari Tengah" << endl;
        cout << "6. Menghapus Node dari Tengah" << endl;
        cout << "7. Menghapus Semua Data" << endl;
        cout << "8. Menampilkan Node" << endl;
        cout << "9. Selesai" << endl;
        cout << "-------------------------------" << endl;

        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            int dataFront;
            cout << "Masukkan Data : ";
            cin >> dataFront;
            insertFromFront(dataFront);
            break;
        case 2:
            int dataBack;
            cout << "Masukkan Data : ";
            cin >> dataBack;
            insertFromBack(dataBack);
            break;
        case 3:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                deleteFromFront();
            }
            break;
        case 4:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                deleteFromBack();
            }
            break;
        case 5:
            int key, dataMid;
            cout << "Masukkan Kunci Node : ";
            cin >> key;
            cout << "Masukkan Data : ";
            cin >> dataMid;
            insertAfter(key, dataMid);
            break;
        case 6:
            int keyDelete;
            cout << "Masukkan Kunci Node yang akan dihapus : ";
            cin >> keyDelete;
            deleteNode(keyDelete);
            break;
        case 7:
            deleteAll();
            break;
        case 8:
            if (isEmpty())
            {
                cout << "Data Kosong!" << endl;
            }
            else
            {
                printNode();
            }
            break;
        case 9:
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

void insertFromFront(int data)
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
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertFromBack(int data)
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
    int dataDeleted;
    if (head->next != NULL)
    {
        del = head;
        dataDeleted = head->data;
        cout << "\n" << dataDeleted << " telah dihapus" << endl;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
    else
    {
        dataDeleted = head->data;
        cout << "\n" << dataDeleted << " telah dihapus" << endl;
        delete head;
        head = NULL;
        tail = NULL;
    }
}

void deleteFromBack()
{
    int dataDeleted;
    if (tail->prev != NULL)
    {
        del = tail;
        dataDeleted = tail->data;
        cout << "\n" << dataDeleted << " telah dihapus" << endl;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
    else
    {
        dataDeleted = tail->data;
        cout << "\n" << dataDeleted << " telah dihapus" << endl;
        delete tail;
        head = NULL;
        tail = NULL;
    }
}

void insertAfter(int key, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            newNode = new Node;
            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

void deleteNode(int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                deleteFromFront();
            }
            else if (temp == tail)
            {
                deleteFromBack();
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            break;
        }
        temp = temp->next;
    }
}

void deleteAll()
{
    while (!isEmpty())
    {
        deleteFromFront();
    }
}

void printNode()
{
    print = head;
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
