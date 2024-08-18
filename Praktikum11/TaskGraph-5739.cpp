#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void printGraph(const vector<Edge>& edges, const vector<char>& vertices) {
    int totalWeight = 0;

    cout << "\nGaris yang dapat dibentuk : ";
    for (size_t i = 0; i < edges.size(); ++i) {
        cout << vertices[edges[i].src - 1] << vertices[edges[i].dest - 1] << ", ";
    }
    cout << "\n\n-------------------------------\n";

    for (size_t i = 0; i < edges.size(); ++i) {
        cout << "Simpul " << vertices[edges[i].src - 1] << " dengan Simpul " << vertices[edges[i].dest - 1] << " : " << edges[i].weight << endl;
        totalWeight += edges[i].weight;
    }

    cout << "\nJarak panjang : " << totalWeight << endl;
}

int main() {
    int V, E;

    cout << "========Weighted Graph=========\n";
    cout << "Input Jumlah Vertex : ";
    cin >> V;
    cout << "Input Jumlah Edge : ";
    cin >> E;

    vector<char> vertices(V);
    vector<Edge> edges(E);

    cout << "-------------------------------\n";
    for (int i = 0; i < V; ++i) {
        cout << "Nama Vertex - [" << i + 1 << "] : ";
        cin >> vertices[i];
    }

    cout << "-------------------------------\n";
    for (int i = 0; i < E; ++i) {
        cout << "Vertex Sumber : ";
        cin >> edges[i].src;
        cout << "Vertex Tujuan : ";
        cin >> edges[i].dest;
        cout << "Weight : ";
        cin >> edges[i].weight;
        cout << "-------------------------------\n";
    }

    printGraph(edges, vertices);

    return 0;
}

