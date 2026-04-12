#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, int> conquests;
    string country;
    while(n--) {
        cin >> country;
        ++conquests[country];
        getline(cin, country);
    }
    vector<pair<string, int>> v(conquests.begin(), conquests.end());
    sort(v.begin(), v.end());
    for(auto p : v)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
