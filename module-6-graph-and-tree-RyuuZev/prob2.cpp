#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> vertex(N);

    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
    }

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:\n";

    for (int i = 0; i < N; i++) {
        cout << vertex[i] << " -> ";

        bool first = true;

        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0) {
                if (!first) cout << ", ";

                cout << "(" << vertex[j]
                     << "," << matrix[i][j] << ")";

                first = false;
            }
        }

        if (first) cout << "-";

        cout << '\n';
    }

    return 0;
}