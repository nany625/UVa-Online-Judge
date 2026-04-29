#include <bits/stdc++.h>
using namespace std;

const int MAXR = 1000;
const int MAXC = 1000;
vector<vector<int>> grid(MAXR, vector<int>(MAXC)), dir = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

int bfs(pair<int, int> start, pair<int, int> dest, int R, int C) {
    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = 0;
    do {
        queue<pair<int, int>> temp;
        do {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nrow = x + dir[0][i];
                int ncol = y + dir[1][i];
                if(nrow >= 0 && nrow < R && ncol >= 0 && ncol < C && grid[nrow][ncol] != -1 && grid[nrow][ncol] == INT_MAX) {
                    grid[nrow][ncol] = grid[x][y] + 1;
                    if(nrow == dest.first && ncol == dest.second)
                        return grid[nrow][ncol];
                    q.emplace(nrow, ncol);
                }
            }
        } while(!q.empty());
        q = temp;
    } while(!q.empty());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    while(cin >> R >> C && R != 0) {
        for(int i = 0; i < R; ++i)
            fill(grid[i].begin(), grid[i].begin() + C, INT_MAX);
        int rows;
        cin >> rows;
        while(rows--) {
            int rowNum, bombs;
            cin >> rowNum >> bombs;
            while(bombs--) {
                int colNum;
                cin >> colNum;
                grid[rowNum][colNum] = -1;
            }
        }
        pair<int, int> start, dest;
        cin >> start.first >> start.second >> dest.first >> dest.second;
        cout << bfs(start, dest, R, C) << '\n';
    }
    return 0;
}
