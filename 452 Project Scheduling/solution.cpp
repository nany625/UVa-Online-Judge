#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
vector<vector<int>> adj(MAXN);
vector<int> indeg(MAXN), days(MAXN);

int topo_sort() {
    queue<int> q;
    for(int i = 0; i < MAXN; ++i) {
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    do {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
    } while(!q.empty());
    vector<int> dist = days;
    for(int u : topo) {
        if(dist[u] == -1)
            continue;
        for(int v : adj[u])
            dist[v] = max(dist[v], dist[u] + days[v]);
    }
    return *max_element(dist.begin(), dist.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    while(cases--) {
        for(int i = 0; i < MAXN; ++i)
            adj[i].clear();
        fill(indeg.begin(), indeg.end(), 0);
        fill(days.begin(), days.end(), -1);
        string line;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            string task, preTask;
            iss >> task >> days[task[0] - 'A'] >> preTask;
            if(!preTask.empty()) {
                for(int i = 0; i < preTask.length(); ++i)
                    adj[preTask[i] - 'A'].push_back(task[0] - 'A');
                indeg[task[0] - 'A'] = preTask.length();
            }
        }
        cout << topo_sort() << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
