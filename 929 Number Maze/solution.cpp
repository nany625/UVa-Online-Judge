#include <bits/stdc++.h>
using namespace std;

const int MAXN = 999;
vector<vector<int>> maze(MAXN, vector<int>(MAXN)), dist(MAXN, vector<int>(MAXN));
vector<vector<int>> dir = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

int dijkstra(int N, int M) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < N; ++i)
        dist[i].assign(M, INT_MAX);
    dist[0][0] = maze[0][0];
    pq.emplace(0, 0);
    do {
        auto [d, u] = pq.top();
        int row = u / M, col = u % M;
        if(row == N - 1 && col == M - 1)
            break;
        pq.pop();
        if(d > dist[row][col])
            continue;
        for(int i = 0; i < 4; ++i) {
            int nrow = row + dir[0][i];
            int ncol = col + dir[1][i];
            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M) {
                if(dist[nrow][ncol] > dist[row][col] + maze[nrow][ncol]) {
                    dist[nrow][ncol] = dist[row][col] + maze[nrow][ncol];
                    pq.emplace(dist[nrow][ncol], nrow * M + ncol);
                }
            }
        }
    } while(!pq.empty());
    return dist[N - 1][M - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int N, M;
        cin >> N >> M;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                cin >> maze[i][j];
                dist[i][j] = INT_MAX;
            }
        }
        cout << dijkstra(N, M) << '\n';
    }
    return 0;
}
