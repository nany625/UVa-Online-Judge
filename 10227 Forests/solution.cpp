#include <bits/stdc++.h>
using namespace std;

const int MAXT = 99;

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
        vector<bitset<MAXT>> hear(P);
        string line;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int i, j;
            iss >> i >> j;
            hear[i - 1].set(j - 1);
        }
        unordered_set<bitset<MAXT>> opinions(hear.begin(), hear.end());
        cout << opinions.size() << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
