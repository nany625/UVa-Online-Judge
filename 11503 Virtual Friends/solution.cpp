#include <bits/stdc++.h>
using namespace std;

const int MAXF = 100000;
vector<int> root(MAXF), depth(MAXF);

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(depth[x] < depth[y])
            swap(x, y);
        depth[x] += depth[y];
        root[y] = x;
    }
    return depth[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        unordered_map<string, int> friendNum;
        int F, cnt = 0;
        cin >> F;
        while(F--) {
            string name1, name2;
            cin >> name1 >> name2;
            if(!friendNum.count(name1)) {
                friendNum[name1] = cnt;
                root[cnt] = cnt;
                depth[cnt++] = 1;
            }
            if(!friendNum.count(name2)) {
                friendNum[name2] = cnt;
                root[cnt] = cnt;
                depth[cnt++] = 1;
            }
            cout << unite(friendNum[name1], friendNum[name2]) << '\n';
        }
    }
    return 0;
}
