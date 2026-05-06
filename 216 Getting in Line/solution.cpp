#include <bits/stdc++.h>
using namespace std;

const int MAXV = 8;
array<array<double, MAXV>, 1 << MAXV> dp;
array<array<double, MAXV>, MAXV> dist;
array<array<int, MAXV>, 1 << MAXV> parent;
vector<int> path;

void findPath(int mask, int e) {
    while(e != -1) {
        path.push_back(e);
        int temp = parent[mask][e];
        mask ^= (1 << e);
        e = temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int networks = 0, computers;
    while(cin >> computers && computers != 0) {
        vector<pair<int, int>> node(computers);
        for(int i = 0; i < computers; ++i)
            cin >> node[i].first >> node[i].second;
        for(int i = 0; i < computers - 1; ++i) {
            for(int j = i + 1; j < computers; ++j)
                dist[i][j] = dist[j][i] = hypot(node[i].first - node[j].first, node[i].second - node[j].second);
        }
        int FULL = 1 << computers;
        double cableLen = INT_MAX;
        for(int i = 0; i < computers; ++i) {
            for(int j = 0; j < FULL; ++j) {
                fill(dp[j].begin(), dp[j].begin() + computers, INT_MAX);
                fill(parent[j].begin(), parent[j].begin() + computers, -1);
            }
            dp[1 << i][i] = 0;
            for(int mask = 1; mask < FULL; ++mask) {
                for(int u = 0; u < computers; ++u) {
                    if(mask & (1 << u)) {
                        for(int v = 0; v < computers; ++v) {
                            if(!(mask & (1 << v))) {
                                int next = mask | (1 << v);
                                if(dp[next][v] > dp[mask][u] + dist[u][v]) {
                                    dp[next][v] = dp[mask][u] + dist[u][v];
                                    parent[next][v] = u;
                                }
                            }
                        }
                    }
                }
            }
            int e = 0;
            for(int j = 1; j < computers; ++j) {
                if(dp[FULL - 1][e] > dp[FULL - 1][j])
                    e = j;
            }
            path.clear();
            if(cableLen > dp[FULL - 1][e]) {
                cableLen = dp[FULL - 1][e];
                findPath(FULL - 1, e);
            }
        }
        cout << "**********************************************************\nNetwork #" << ++networks << '\n';
        for(int i = computers - 1; i > 0; --i)
            cout << "Cable requirement to connect (" << node[path[i]].first << ',' << node[path[i]].second << ") to (" << node[path[i - 1]].first << ',' << node[path[i - 1]].second << ") is " << fixed << setprecision(2) << 16 + dist[path[i]][path[i - 1]] << " feet.\n";
        cout << "Number of feet of cable required is " << cableLen + 16 * (computers - 1) << ".\n";
    }
    return 0;
}
