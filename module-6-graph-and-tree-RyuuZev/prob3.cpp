#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int r;
    int c;
};

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc;
    int fr, fc;

    cin >> sr >> sc;
    cin >> fr >> fc;

    vector<vector<int>> dist(R, vector<int>(C, -1));

    queue<State> q;

    q.push({sr, sc});
    dist[sr][sc] = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if (nr < 0 || nr >= R ||
                nc < 0 || nc >= C)
                continue;

            if (grid[nr][nc] == 1)
                continue;

            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({nr, nc});
        }
    }

    cout << dist[fr][fc] << '\n';

    return 0;
}