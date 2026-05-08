#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
array<vector<int>, MAXN> adj;
array<int, MAXN> indeg;

vector<int> topo_sort(int n) {
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < n; ++i) {
        if(indeg[i] == 0)
            pq.push(i);
    }
    vector<int> topo;
    do {
        int u = pq.top();
        pq.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            if(--indeg[v] == 0)
                pq.push(v);
        }
    } while(!pq.empty());
    return topo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, N;
    while(cin >> N) {
        fill(indeg.begin(), indeg.begin() + N, 0);
        unordered_map<string, int> beverageNum;
        vector<string> beverage(N);
        for(int i = 0; i < N; ++i) {
            adj[i].clear();
            cin >> beverage[i];
            beverageNum[beverage[i]] = i;
        }
        int M;
        cin >> M;
        string B1, B2;
        while(M--) {
            cin >> B1 >> B2;
            int u = beverageNum[B1];
            int v = beverageNum[B2];
            adj[u].push_back(v);
            ++indeg[v];
        }
        vector<int> topo = topo_sort(N);
        cout << "Case #" << ++cases << ": Dilbert should drink beverages in this order:";
        for(int x : topo)
            cout << ' ' << beverage[x];
        cout << ".\n\n";
    }
    return 0;
}
