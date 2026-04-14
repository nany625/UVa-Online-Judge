#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    while(cases--) {
        int P, T;
        cin >> P >> T;
        vector<string> hear(P);
        for(auto s : hear)
            s.assign(T, '0');
        string line;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int i, j;
            iss >> i >> j;
            hear[i - 1][j - 1] = '1';
        }
        unordered_set<string> opinions;
        for(string s : hear)
            opinions.insert(s);
        cout << opinions.size() << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
