#include <bits/stdc++.h>
using namespace std;

const int INF = 50;
vector<vector<int>> dist(50, vector<int>(50));

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dataSets = 0, P, R;
    while(cin >> P >> R && P != 0) {
        for(int i = 0; i < P; ++i) {
            for(int j = 0; j < P; ++j)
                dist[i][j] = i == j ? 0 : INF;
        }
        unordered_map<string, int> peopleNum;
        string name1, name2;
        while(R--) {
            cin >> name1 >> name2;
            if(!peopleNum.count(name1))
                peopleNum[name1] = peopleNum.size();
            if(!peopleNum.count(name2))
                peopleNum[name2] = peopleNum.size();
            dist[peopleNum[name1]][peopleNum[name2]] = dist[peopleNum[name2]][peopleNum[name1]] = 1;
        }
        floydWarshall(P);
        int ans = 1;
        for(int i = 0; i < P; ++i) {
            for(int j = 0; j < P; ++j)
                ans = max(ans, dist[i][j]);
        }
        if(ans == INF)
            cout << "Network " << ++dataSets << ": DISCONNECTED\n\n";
        else
            cout << "Network " << ++dataSets << ": " << ans << "\n\n";
    }
    return 0;
}
