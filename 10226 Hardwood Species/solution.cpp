#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    string name;
    while(cases--) {
        unordered_map <string, int> tree;
        int cnt = 0;
        while(getline(cin, name) && !name.empty()) {
            ++tree[name];
            ++cnt;
        }
        vector<pair<string, int>> v(tree.begin(), tree.end());
        sort(v.begin(), v.end());
        for(auto p : v)
            cout << p.first << ' ' << fixed << setprecision(4) << 100.0 * p.second / cnt << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
