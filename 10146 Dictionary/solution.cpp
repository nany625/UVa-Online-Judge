#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    cin.ignore();
    string prev;
    while(cases--) {
        getline(cin, prev);
        cout << prev << '\n';
        string curr;
        int i = 0;
        while(getline(cin, curr) && !curr.empty()) {
            int j = 0;
            while(j < prev.length() && j < curr.length() && prev[j] == curr[j])
                ++j;
            i = min(i + 1, j);
            for(j = 0; j < i; ++j)
                cout << ' ';
            cout << curr << '\n';
            prev = curr;
        }
        if(cases)
            cout << '\n';
    }
    return 0;
}
