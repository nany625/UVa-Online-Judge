#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
vector<vector<pair<int, int>>> adj(MAXN + 1);
vector<int> dist1(MAXN + 1), dist2(MAXN + 1), pre1(MAXN + 1), pre2(MAXN + 1);

void dijkstra1(int N, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist1.assign(N + 1, 1e9);
    dist1[S] = 0;
    iota(pre1.begin(), pre1.begin() + N + 1, 0);
    pq.emplace(0, S);
    do {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist1[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(dist1[v] > dist1[u] + w) {
                dist1[v] = dist1[u] + w;
                pq.emplace(dist1[v], v);
                pre1[v] = u;
            }
        }
    } while(!pq.empty());
}

void dijkstra2(int N, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist2.assign(N + 1, 1e9);
    dist2[S] = 0;
    iota(pre2.begin(), pre2.begin() + N + 1, 0);
    pq.emplace(0, S);
    do {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist2[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                pq.emplace(dist2[v], v);
                pre2[v] = u;
            }
        }
    } while(!pq.empty());
}

vector<int> findPath(pair<int, int> CXpress, int E) {
    vector<int> path;
    //沒使用ticket
    if(CXpress.first == -1) {
        while(E != pre1[E]) {
            path.push_back(E);
            E = pre1[E];
        }
        path.push_back(E);
        return path;
    }
    E = CXpress.second;
    while(E != pre2[E]) {
        path.push_back(E);
        E = pre2[E];
    }
    path.push_back(E);
    reverse(path.begin(), path.end());
    E = CXpress.first;
    while(E != pre1[E]) {
        path.push_back(E);
        E = pre1[E];
    }
    path.push_back(E);
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, S, E;
    bool firstCase = true;
    while(cin >> N >> S >> E) {
        if(!firstCase)
            cout << '\n';
        for(int i = 1; i <= N; ++i)
            adj[i].clear();
        int M;
        cin >> M;
        while(M--) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            adj[X].emplace_back(Y, Z);
            adj[Y].emplace_back(X, Z);
        }
        dijkstra1(N, S);
        dijkstra2(N, E);
        int K;
        cin >> K;
        int ans = dist1[E];
        pair<int, int> CXpress = {-1, -1};
        while(K--) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            if(ans > dist1[X] + dist2[Y] + Z) {
                ans = dist1[X] + dist2[Y] + Z;
                CXpress = {X, Y};
            }
            if(ans > dist1[Y] + dist2[X] + Z) {
                ans = dist1[Y] + dist2[X] + Z;
                CXpress = {Y, X};
            }
        }
        vector<int> path = findPath(CXpress, E);
        cout << path.back();
        if(CXpress.first == -1) {
            for(int i = path.size() - 2; i >= 0; --i)
                cout << ' ' << path[i];
            cout << "\nTicket Not Used\n" << ans << '\n';
        } else {
            for(int i = path.size() - 2; i >= 0; --i)
                cout << ' ' << path[i];
            cout << '\n' << CXpress.first << '\n' << ans << '\n';
        }
        firstCase = false;
    }
    return 0;
}
