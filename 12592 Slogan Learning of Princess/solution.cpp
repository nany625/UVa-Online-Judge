#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore();
    unordered_map<string, string> slogans;
    string first, second;
    while(N--) {
        getline(cin, first);
        getline(cin, second);
        slogans[first] = second;
    }
    int Q;
    cin >> Q;
    cin.ignore();
    while(Q--) {
        getline(cin, first);
        cout << slogans[first] << '\n';
    }
    return 0;
}
