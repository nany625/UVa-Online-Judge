#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
array<array<string, MAX>, MAX> maze;
array<array<array<int, MAX>, MAX>, MAX> times;
array<array<int, 6>, 3> dir = {{
    {{-1, 1, 0, 0, 0, 0}},
    {{0, 0, -1, 1, 0, 0}},
    {{0, 0, 0, 0, -1, 1}}
}};

void bfs(queue<tuple<int, int, int>>& q, int L, int R, int C) {
    while(!q.empty()) {
        auto [x, y, z] = q.front();
        for(int i = 0; i < 6; ++i) {
            int nx = x + dir[0][i];
            int ny = y + dir[1][i];
            int nz = z + dir[2][i];
            if(nx >= 0 && nx < L && ny >= 0 && ny < R && nz >= 0 && nz < C && maze[nx][ny][nz] != '#' && times[nx][ny][nz] == -1) {
                times[nx][ny][nz] = times[x][y][z] + 1;
                if(maze[nx][ny][nz] == 'E') {
                    cout << "Escaped in " << times[nx][ny][nz] << " minute(s).\n";
                    return;
                }
                q.emplace(nx, ny, nz);
            }
        }
        q.pop();
    }
    cout << "Trapped!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, R, C;
    while(cin >> L >> R >> C && L != 0) {
        for(int i = 0; i < L; ++i) {
	        for(int j = 0; j < R; ++j)
	            cin >> maze[i][j];
	    }
	    queue<tuple<int, int, int>> q;
	    for(int i = 0; i < L; ++i) {
	        for(int j = 0; j < R; ++j) {
	            for(int k = 0; k < C; ++k) {
	                if(maze[i][j][k] == 'S') {
	                    q.emplace(i, j, k);
	                    times[i][j][k] = 0;
	                } else
	                    times[i][j][k] = -1;
	            }
	        }
	    }
	    bfs(q, L, R, C);
    }
    return 0;
}
