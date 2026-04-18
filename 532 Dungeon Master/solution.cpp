#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
const int INF = 1e9;
vector<vector<string>> maze(MAX, vector<string>(MAX));
vector<vector<vector<int>>> times(MAX, vector<vector<int>>(MAX, vector<int>(MAX)));
tuple<int, int, int> endss;

void bfs(queue<tuple<int, int, int>> q, int L, int R, int C) {
    while(!q.empty() && q.front() != endss) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        if(x > 0 && maze[x - 1][y][z] != '#' && times[x - 1][y][z] == INF) {
            times[x - 1][y][z] = times[x][y][z] + 1;
            q.push(make_tuple(x - 1, y, z));
        }
        if(x + 1 < L && maze[x + 1][y][z] != '#' && times[x + 1][y][z] == INF) {
            times[x + 1][y][z] = times[x][y][z] + 1;
            q.push(make_tuple(x + 1, y, z));
        }
        if(y > 0 && maze[x][y - 1][z] != '#' && times[x][y - 1][z] == INF) {
            times[x][y - 1][z] = times[x][y][z] + 1;
            q.push(make_tuple(x, y - 1, z));
        }
        if(y + 1 < R && maze[x][y + 1][z] != '#' && times[x][y + 1][z] == INF) {
            times[x][y + 1][z] = times[x][y][z] + 1;
            q.push(make_tuple(x, y + 1, z));
        }
        if(z > 0 && maze[x][y][z - 1] != '#' && times[x][y][z - 1] == INF) {
            times[x][y][z - 1] = times[x][y][z] + 1;
            q.push(make_tuple(x, y, z - 1));
        }
        if(z + 1 < C && maze[x][y][z + 1] != '#' && times[x][y][z + 1] == INF) {
            times[x][y][z + 1] = times[x][y][z] + 1;
            q.push(make_tuple(x, y, z + 1));
        }
        q.pop();
    }
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
	                times[i][j][k] = INF;
	                if(maze[i][j][k] == 'S') {
	                    q.push(make_tuple(i, j, k));
	                    times[i][j][k] = 0;
	                } else if(maze[i][j][k] == 'E')
	                    endss = make_tuple(i, j, k);
	            }
	        }
	    }
	    bfs(q, L, R, C);
	    if(times[get<0>(endss)][get<1>(endss)][get<2>(endss)] == INF)
	        cout << "Trapped!\n";
	    else
	        cout << "Escaped in " << times[get<0>(endss)][get<1>(endss)][get<2>(endss)] << " minute(s).\n";
    }
    return 0;
}
