#include <bits/stdc++.h>
using namespace std;

const int MAXR = 1000;
const int MAXC = 1000;
vector<string> maze(MAXR);
vector<vector<int>> dist(MAXR, vector<int>(MAXC)), fire(MAXR, vector<int>(MAXC)), dir = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

pair<int, int> findJoe(int R, int C) {
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(maze[i][j] == 'J') {
                dist[i][j] = 0;
                return {i, j};
            }
        }
    }
}

void findFire(queue<pair<int, int>>& q, int R, int C) {
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(maze[i][j] == 'F') {
                fire[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
}

void spread(queue<pair<int, int>>& q, int R, int C) {
    queue<pair<int, int>> temp;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[0][i];
            int ny = y + dir[1][i];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C && maze[nx][ny] != '#' && fire[nx][ny] == -1) {
                temp.emplace(nx, ny);
                fire[nx][ny] = fire[x][y] + 1;
            }
        }
    }
    swap(q, temp);
}

int bfs(int R, int C) {
    queue<pair<int, int>> fireQueue;
    findFire(fireQueue, R, C);
    queue<pair<int, int>> q;
    q.push(findJoe(R, C));
    do {
        spread(fireQueue, R, C);
        queue<pair<int, int>> temp;
        do {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dir[0][i];
                int ny = y + dir[1][i];
                if(nx < 0 || nx == R || ny < 0 || ny == C)
                    return dist[x][y] + 1;
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && maze[nx][ny] != '#' && dist[nx][ny] == -1 && (fire[nx][ny] == -1 || fire[nx][ny] > dist[x][y] + 1)) {
                    temp.emplace(nx, ny);
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        } while(!q.empty());
        swap(q, temp);
    } while(!q.empty());
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int R, C;
        cin >> R >> C;
        for(int i = 0; i < R; ++i) {
            fill(dist[i].begin(), dist[i].begin() + C, -1);
            fill(fire[i].begin(), fire[i].begin() + C, -1);
            cin >> maze[i];
        }
        int ans = bfs(R, C);
        if(ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
