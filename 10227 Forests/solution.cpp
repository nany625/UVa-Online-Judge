#include <bits/stdc++.h>
using namespace std;

array<bitset<99>, 99> hear;

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
        cin.ignore();
        for(int i = 0; i < P; ++i)
            hear[i].reset();
        string line;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int i, j;
            iss >> i >> j;
            hear[i - 1][j - 1] = 1;
        }
        unordered_set<bitset<99>> opinions(hear.begin(), hear.begin() + P);
        cout << opinions.size() << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
