#include <iostream>
using namespace std;

int main()
{
    int jumlah_vertex, jumlah_edge;

    cout << "Masukkan jumlah vertex: ";
    cin >> jumlah_vertex;

    int matrix[jumlah_vertex+1][jumlah_vertex+1];

    for (int i = 1; i <= jumlah_vertex; i++)
    {
        for (int j = 1; j <= jumlah_vertex; j++)
        {
            matrix[i][j] = 0;
        }
    }

    cout << "Masukkan jumlah edge: ";
    cin >> jumlah_edge;

    for (int i = 1; i <= jumlah_edge; i++)
    {
        int sumber, tujuan;
        cout << "Vertex sumber: ";
        cin >> sumber;
        cout << "Vertex tujuan: ";
        cin >> tujuan;
        matrix[sumber][tujuan] = 1;
        matrix[tujuan][sumber] = 1;
    }

    int i = 1;
    bool nolsemua = false;
    while (i <= jumlah_vertex && !nolsemua)
    {
        int j = 1;
        bool ketemu = false;
        while (j <= jumlah_vertex && !ketemu)
        {
            if (matrix[i][j] == 1)
            {
                ketemu = true;
            }
            else
            {
                j++;
            }
        }
        if (!ketemu)
        {
            nolsemua = true;
        }
        else
        {
            i++;
        }
    }
    if (nolsemua)
    {
        cout << "Grafh tidak terhubung\n";
    }
    else
    {
        cout << "Grafh terhubung\n";
    }

    return 0;
}
