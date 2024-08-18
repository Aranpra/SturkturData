#include <iostream>
using namespace std;

const int MAX_QUEUE = 5;

struct Queue {
    int depan;
    int belakang;
    int data[MAX_QUEUE];
};

void inisialisasi(Queue &queue);
void enqueue(Queue &queue, int nomorAntrian);
void dequeue(Queue &queue);
void clear(Queue &queue);
bool isEmpty(const Queue &queue);
bool isFull(const Queue &queue);
void print(const Queue &queue);

int main() {
    Queue queue;
    inisialisasi(queue);

    int pilihanMenu;
    int nomorAntrian = 1;

    do {
        cout << "             SYSTEM ANTRIAN         " << endl << endl;
        cout << "|1. Menambah Antrian                  |" << endl;
        cout << "|2. Panggil Antrian                   |" << endl;
        cout << "|3. Menampilkan semua daftar Antrian  |" << endl;
        cout << "|4. Hapus Semua daftar Antrian        |" << endl;
        cout << "|5. Keluar Sistem                     |" << endl << endl;
        
        cout << "Masukkan No Pilihan Anda: "; cin >> pilihanMenu;
        cout << endl;

        switch (pilihanMenu) {
            case 1:
                if (isFull(queue)) {
                    cout << "Antrian sudah penuh!!!" << endl;
                } else {
                    enqueue(queue, nomorAntrian);
                    nomorAntrian++;
                }
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                print(queue);
                break;
            case 4:
                clear(queue);
                break;
            case 5:
                break;
            default:
                cout << "Menu yang Anda pilih tidak terdaftar" << endl;
                break;
        }
    } while (pilihanMenu != 5);

    cout << endl;
    system("pause");
    return 0;
}

void inisialisasi(Queue &queue) {
    queue.depan = queue.belakang = -1;
}

void enqueue(Queue &queue, int nomorAntrian) {
    if (queue.belakang == MAX_QUEUE - 1) {
        cout << "Antrian sudah penuh!!!" << endl << endl;
        return;
    }

    if (queue.depan == -1) {
        queue.depan = 0;
    }

    queue.belakang++;
    queue.data[queue.belakang] = nomorAntrian;
    
    cout << "Nomor Antrian          : " << queue.data[queue.belakang] << endl;
    cout << "Antrian yang Menunggu  : " << (queue.belakang - queue.depan) << endl << endl;
}

void dequeue(Queue &queue) {
    if (queue.depan == -1) {
        cout << "Antrian kosong. Tidak ada yang bisa dipanggil." << endl << endl;
        return;
    }

    cout << "No. Antrian " << queue.data[queue.depan] << endl;
    cout << "Silahkan! Anda Dipanggil" << endl;

    for (int i = queue.depan; i < queue.belakang; i++) {
        queue.data[i] = queue.data[i + 1];
    }

    queue.belakang--;

    if (queue.belakang == -1) {
        queue.depan = -1;
    }
}

void clear(Queue &queue) {
    queue.depan = queue.belakang = -1;
    cout << "Daftar Antrian sudah dihapus" << endl << endl;
}

bool isEmpty(const Queue &queue) {
    return (queue.depan == -1);
}

bool isFull(const Queue &queue) {
    return (queue.belakang == MAX_QUEUE - 1);
}

void print(const Queue &queue) {
    if (queue.depan == -1) {
        cout << "Daftar Antrian kosong" << endl << endl;
        return;
    }

    cout << "No. Antrian yang dipanggil: " << queue.data[queue.depan] << endl;
    cout << "Daftar Antrian: ";

    for (int i = queue.depan; i <= queue.belakang; i++) {
        cout << queue.data[i] << " ";
    }

    cout << endl << endl;
}

