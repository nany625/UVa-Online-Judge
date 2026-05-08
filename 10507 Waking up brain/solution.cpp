#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
array<vector<int>, MAXN> adj;
array<int, MAXN> indeg;

void topo_sort(int n, string& dirSti) {
    vector<int> q;
    for(int i = 0; i < dirSti.length(); ++i) {
        indeg[dirSti[i] - 'A'] = 0;
        q.push_back(dirSti[i] - 'A');
    }
    vector<int> topo;
    int year = 0;
    do {
        topo = q;
        q.clear();
        for(int u : topo) {
            for(int v : adj[u]) {
                if(--indeg[v] == 0) {
                    q.push_back(v);
                    --n;
                }
            }
        }
        if(!q.empty())
            ++year;
    } while(!q.empty());
    if(n == 0)
        cout << "WAKE UP IN, " << year << ", YEARS\n";
    else
        cout << "THIS BRAIN NEVER WAKES UP\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N) {
        for(int i = 0; i < MAXN; ++i)
            adj[i].clear();
        fill(indeg.begin(), indeg.end(), 3);
        int M;
        cin >> M;
        string dirSti;
        cin >> dirSti;
        string conn;
        while(M--) {
            cin >> conn;
            adj[conn[0] - 'A'].push_back(conn[1] - 'A');
            adj[conn[1] - 'A'].push_back(conn[0] - 'A');
        }
        topo_sort(N - dirSti.length(), dirSti);
    }
    return 0;
}
