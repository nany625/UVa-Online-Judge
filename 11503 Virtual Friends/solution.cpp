#include <bits/stdc++.h>
using namespace std;

const int MAXF = 200000;
vector<int> root(MAXF), depth(MAXF);

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
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
            int root1 = find(friendNum[name1]), root2 = find(friendNum[name2]);
            if(root1 != root2) {
                depth[root1] += depth[root2];
                root[root2] = root1;
            }
            cout << depth[root1] << '\n';
        }
    }
    return 0;
}
