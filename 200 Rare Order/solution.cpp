#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
vector<int> adj[MAXN];
array<int, MAXN> indeg;
unordered_map<char, int> charNum;
vector<char> charDict;

void topo_sort() {
    queue<int> q;
    for(int i = 0; i < charDict.size(); ++i) {
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
    for(int x : topo)
        cout << charDict[x];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string pre, nxt;
    cin >> pre;
    charNum[pre[0]] = 0;
    charDict.push_back(pre[0]);
    int id = 1;
    while(cin >> nxt && nxt[0] != '#') {
        int mn = min(pre.length(), nxt.length());
        for(int i = 0; i < mn; ++i) {
            if(pre[i] != nxt[i]) {
                if(!charNum.count(pre[i])) {
                    charNum[pre[i]] = id++;
                    charDict.push_back(pre[i]);
                }
                if(!charNum.count(nxt[i])) {
                    charNum[nxt[i]] = id++;
                    charDict.push_back(nxt[i]);
                }
                int u = charNum[pre[i]];
                int v = charNum[nxt[i]];
                adj[u].push_back(v);
                ++indeg[v];
                break;
            }
        }
        swap(pre,nxt);
    }
    topo_sort();
    return 0;
}
