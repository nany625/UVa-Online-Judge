#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
vector<vector<int>> adj(MAXN + 1);
bitset<MAXN + 1> visited;

void init(int N) {
    for(int i = 1; i <= N; ++i)
        adj[i].clear();
}

int bfs() {
    visited.reset();
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int root = 1;
    do {
        queue<int> temp;
        do {
            int u = q.front();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    temp.push(v);
                    visited[v] = 1;
                    root = v;
                }
            }
            q.pop();
        } while(!q.empty());
        q = temp;
    } while(!q.empty());
    return root;
}

int bfs(int S) {
    visited.reset();
    queue<int> q;
    q.push(S);
    visited[S] = 1;
    int ans = 0;
    do {
        queue<int> temp;
        do {
            int u = q.front();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    temp.push(v);
                    visited[v] = 1;
                    if(temp.size() == 1)
                        ++ans;
                    else
                        ans += 2;
                }
            }
            q.pop();
        } while(!q.empty());
        q = temp;
    } while(!q.empty());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        init(N);
        for(int u = 1; u <= N; ++u) {
            int M;
            cin >> M;
            while(M--) {
                int v;
                cin >> v;
                adj[u].push_back(v);
            }
        }
        cout << bfs(bfs()) << '\n';
    }
    return 0;
}
