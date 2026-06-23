#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> vertex(N);
    map<char, int> pos;

    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
        pos[vertex[i]] = i;
    }

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        char u, v;
        int w;

        cin >> u >> v >> w;

        matrix[pos[u]][pos[v]] = w;
    }

    cout << "Adjacency Matrix:\n";

    cout << " ";
    for (char c : vertex) {
        cout << " " << c;
    }
    cout << '\n';

    for (int i = 0; i < N; i++) {
        cout << vertex[i];

        for (int j = 0; j < N; j++) {
            cout << " " << matrix[i][j];
        }

        cout << '\n';
    }

    return 0;
}