#include <iostream>
#include <vector>
using namespace std;

int R, C;
int sr, sc;
int fr, fc;

vector<vector<int>> grid;
vector<vector<bool>> visited;

long long totalPath = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == fr && c == fc) {
        totalPath++;
        return;
    }

    visited[r][c] = true;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr < 0 || nr >= R ||
            nc < 0 || nc >= C)
            continue;

        if (grid[nr][nc] == 1)
            continue;

        if (visited[nr][nc])
            continue;

        dfs(nr, nc);
    }

    visited[r][c] = false;
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> sr >> sc;
    cin >> fr >> fc;

    visited.assign(R, vector<bool>(C, false));

    dfs(sr, sc);

    cout << "\nOutput" << endl;
    cout << totalPath << '\n';

    return 0;
}