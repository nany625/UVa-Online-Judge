#include <bits/stdc++.h>
using namespace std;

array<int, 40401> dist;
array<int, 201> ans;
int a, b, c, d;

int state(int y, int z) {
    return y * 201 + z;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, state(0, c));
    dist.fill(INT_MAX);
    dist[state(0, c)] = 0;
    ans.fill(INT_MAX);
    ans[0] = ans[c] = 0;
    do {
        auto [dd, u] = pq.top();
        int z = u % 201;
        int y = u / 201;
        int x = c - y - z;
        if(x == d || y == d || z == d)
            break;
        pq.pop();
        if(dd > dist[u])
            continue;
        if(x != 0) {
            if(y != b) {
                int amount = min(x, b - y);
                int v = state(y + amount, z);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[x - amount] = min(ans[x - amount], dist[v]);
                    ans[y + amount] = min(ans[y + amount], dist[v]);
                }
            }
            if(z != c) {
                int amount = min(x, c - z);
                int v = state(y, z + amount);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[x - amount] = min(ans[x - amount], dist[v]);
                    ans[z + amount] = min(ans[z + amount], dist[v]);
                }
            }
        }
        if(y != 0) {
            if(x != a) {
                int amount = min(y, a - x);
                int v = state(y - amount, z);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[y - amount] = min(ans[y - amount], dist[v]);
                    ans[x + amount] = min(ans[x + amount], dist[v]);
                }
            }
            if(z != c) {
                int amount = min(y, c - z);
                int v = state(y - amount, z + amount);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[y - amount] = min(ans[y - amount], dist[v]);
                    ans[z + amount] = min(ans[z + amount], dist[v]);
                }
            }
        }
        if(z != 0) {
            if(x != a) {
                int amount = min(z, a - x);
                int v = state(y, z - amount);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[z - amount] = min(ans[z - amount], dist[v]);
                    ans[x + amount] = min(ans[x + amount], dist[v]);
                }
            }
            if(y != b) {
                int amount = min(z, b - y);
                int v = state(y + amount, z - amount);
                if(dist[v] > dist[u] + amount) {
                    dist[v] = dist[u] + amount;
                    pq.emplace(dist[v], v);
                    ans[z - amount] = min(ans[z - amount], dist[v]);
                    ans[y + amount] = min(ans[y + amount], dist[v]);
                }
            }
        }
    } while(!pq.empty());
    while(ans[d] == INT_MAX)
        --d;
    cout << ans[d] << ' ' << d << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d;
        dijkstra();
    }
    return 0;
}
