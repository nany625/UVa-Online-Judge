#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        cin >> str;
        sort(str.begin(), str.end());
        do {
            cout << str << '\n';
        } while(next_permutation(str.begin(), str.end()));
        cout << '\n';
    }
    return 0;
}
