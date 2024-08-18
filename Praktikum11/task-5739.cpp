#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_VERTEX = 100; // Ubah sesuai kebutuhan

struct Edge {
    int to;
    int weight;
};

int main() {
    int jumlah_vertex, jumlah_edge;
    bool nolsemua = false;
    int matrix[MAX_VERTEX][MAX_VERTEX];

    // Pilih tipe graf
    int tipe_graf;
    cout << "================Graph================" << endl;
    cout << "Menu Graph:" << endl;
    cout << "1. Undirected Graph" << endl;
    cout << "2. Directed Graph" << endl;
    cout << "3. Weighted Graph" << endl;
    cout << "4. Selesai" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> tipe_graf;

    if (tipe_graf == 4) {
        cout << "Program selesai." << endl;
        return 0;
    }

    if (tipe_graf < 1 || tipe_graf > 3) {
        cout << "Pilihan tidak valid." << endl;
        return 0;
    }

    // Input jumlah vertex dan edge
    cout <<"================Graph================" << endl;
    cout << "Input Jumlah Vertex : ";
    cin >> jumlah_vertex;
    cout << "Input Jumlah Edge : ";
    cin >> jumlah_edge;

    // Input nama vertex
    string nama_vertex[MAX_VERTEX];
    for (int i = 1; i <= jumlah_vertex; i++) {
        cout << "Nama Vertex - [" << i << "] : ";
        cin >> nama_vertex[i];
    }

    // Inisialisasi matriks dengan nilai 0
    for (int i = 1; i <= jumlah_vertex; i++) {
        for (int j = 1; j <= jumlah_vertex; j++) {
            matrix[i][j] = 0;
        }
    }

    // Pengisian matriks asal ke tujuan
    cout << "Masukkan edge(s):\n";
    for (int i = 1; i <= jumlah_edge; i++) {
        int sumber, tujuan;
        cout << "------------------------"  << endl;
        cout << "Vertex Sumber : ";
        cin >> sumber;
        cout << "Vertex Tujuan : ";
        cin >> tujuan;\
        
        if (tipe_graf == 3) {
            int bobot;
            cout << "Bobot : ";
            cin >> bobot;
            matrix[sumber][tujuan] = bobot;
        } else {
            matrix[sumber][tujuan] = 1;
            if (tipe_graf == 1) {
                matrix[tujuan][sumber] = 1; // Jika undirected graph
            }
        }
        
    }

    // Menampilkan simpul asal dan tujuan
    cout << "\nGaris yang dapat dibentuk : ";
    for (int i = 1; i <= jumlah_vertex; i++) {
        for (int j = 1; j <= jumlah_vertex; j++) {
            if (matrix[i][j] != 0) {
                if (tipe_graf == 3) {
                    cout << nama_vertex[i] << nama_vertex[j] << " (Bobot: " << matrix[i][j] << "), ";
                } else {
                    cout << nama_vertex[i] << nama_vertex[j] << ", ";
                }
            }
        }
    }
    cout << endl;

    // Menemukan keterhubungan graph
    int i = 1, j;
    while (i <= jumlah_vertex && !nolsemua) {
        j = 1;
        bool ketemu = false;
        while (j <= jumlah_vertex && !ketemu) {
            if (matrix[i][j] != 0) {
                ketemu = true;
            } else {
                j++;
            }
        }
        if (!ketemu) {
            nolsemua = true;
        } else {
            i++;
        }
    }

    // Output keterhubungan graph
    if (nolsemua) {
        cout << "\nGraph tidak terhubung\n";
    } else {
        cout << "\nGraph terhubung\n";
    }

    return 0;
}

